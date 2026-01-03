#pragma once

#include "../../../common/events/view.hpp"
#include "../../../value_object/warrior/warrior_id.hpp"

namespace core {
namespace model {

class IWarriorEvent : common::event::IEvent {
  value_object::WarriorID id_;

 public:
  virtual ~IWarriorEvent() = default;
  constexpr explicit IWarriorEvent(value_object::warrior_id id) noexcept
      : id_(id) {}
  constexpr auto id() const noexcept { return id_.id(); }
};

}  // namespace model
}  // namespace core