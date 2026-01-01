#pragma once

#include <concepts>
#include <memory>
#include <type_traits>

namespace core {
namespace common {
namespace event {

struct IEvent {
  virtual ~IEvent() = default;
};

using EventPtr = std::unique_ptr<IEvent>;

template <typename Event>
concept event_type = std::derived_from<Event, IEvent>;

}  // namespace event
}  // namespace common
}  // namespace core