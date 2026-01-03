#pragma once

#include "../../level/level_entity.hpp"
#include "warrior_event.hpp"

namespace core {
namespace model {

template <typename Entity>
class LevelUpgradedEvent final : public IWarriorEvent {
  Entity* entity_;
  Level old_, new_;

 public:
  constexpr explicit LevelUpgradedEvent(auto id, Entity* entity, auto oldL,
                                        auto newL) noexcept
      : IWarriorEvent(id), entity_(entity), old_(oldL), new_(newL) {}
  constexpr auto entity() const noexcept { return entity_; }
  constexpr auto oldL() const noexcept { return old_; }
  constexpr auto newL() const noexcept { return new_; }
};

}  // namespace model
}  // namespace core