#pragma once

#include "view.hpp"

#include <memory>
#include <queue>

namespace core {
namespace common {
namespace event {

class Queue {
  std::queue<EventPtr> events_;

 public:
  template <event_type Event, typename... Args>
  requires std::constructible_from<Event, Args...>
  void create_event(Args&&... args) {
    events_.emplace(std::make_unique<Event>(std::forward<Args>(args)...));
  }

  EventPtr pull_event() {
    if (events_.empty()) return nullptr;
    EventPtr res = std::move(events_.front());
    events_.pop();
    return res;
  }
};

}  // namespace event
}  // namespace common
}  // namespace core