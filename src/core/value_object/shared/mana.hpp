#pragma once

#include "experience.hpp"

#include <cassert>

namespace core {
namespace value_object {

using mana_value = uint32_t;
using mana_to_exp_factor = float;

class Mana final : public details::GameCurrency<mana_value> {
 public:
  Mana() = default;
  constexpr Mana(mana_value mv) noexcept : GameCurrency(mv) {}
  constexpr details::GameCurrency<experience_value> to_experience(
      mana_to_exp_factor factor) const noexcept {
    assert(0 < factor && factor <= 1);
    return details::GameCurrency<experience_value>(val_ * factor);
  }
};

}  // namespace value_object
}  // namespace core