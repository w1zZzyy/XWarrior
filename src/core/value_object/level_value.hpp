#pragma once

#include <cstdint>

namespace core {
namespace value_object {

using level_value = uint8_t;

class LevelValue {
  level_value val_;

 public:
  LevelValue() = default;
  constexpr LevelValue(level_value val) noexcept : val_(val) {}
  constexpr level_value value() const noexcept { return val_; }
};

}  // namespace value_object
}  // namespace core