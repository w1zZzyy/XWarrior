#pragma once

#include <cstdint>

namespace core {
namespace value_object {

using level_id = uint8_t;

class LevelID {
  level_id id_;

 public:
  LevelID() = default;
  constexpr LevelID(level_id id) noexcept : id_(id) {}
  constexpr level_id id() const noexcept { return id_; }
};

}  // namespace value_object
}  // namespace core