#pragma once

#include "../../value_object/shared/experience.hpp"
#include "value.hpp"

namespace core {
namespace model {

class Level {
  using Exp = value_object::Experience;
  LevelValue value_;
  Exp required_exp_;

 public:
  constexpr Level() = default;
  constexpr Level(LevelValue value, Exp required_exp) noexcept
      : value_(value), required_exp_(required_exp) {}
  constexpr bool canUpgrade(Exp exp) const noexcept {
    return exp.hasEnough(required_exp_);
  }
  constexpr LevelValue value() const noexcept { return value_; }
  constexpr void upgrade() noexcept { ++value_; }
};

}  // namespace model
}  // namespace core