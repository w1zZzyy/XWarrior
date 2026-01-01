#pragma once

#include <cstdint>

namespace core {
namespace model {

class LevelValue {
  using level_value = uint8_t;
  level_value val_;

 public:
  constexpr LevelValue() = default;
  constexpr LevelValue(level_value val) noexcept : val_(val) {}
  constexpr operator int() const noexcept { return val_; }
  constexpr int operator++() noexcept { return val_++; }
};

}  // namespace model
}  // namespace core