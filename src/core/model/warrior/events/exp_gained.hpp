#pragma once

#include "../../../value_object/shared/experience.hpp"
#include "warrior_event.hpp"

namespace core {
namespace model {

template <typename Entity>
class ExpGainedEvent final : public IWarriorEvent {
  Entity* entity_;
  value_object::Experience exp_;

 public:
  constexpr explicit ExpGainedEvent(auto id, Entity* entity, auto exp) noexcept
      : IWarriorEvent(id), entity_(entity), exp_(exp) {}
  constexpr auto entity() const noexcept { return entity_; }
  constexpr auto exp() const noexcept { return exp_; }
};

}  // namespace model
}  // namespace core