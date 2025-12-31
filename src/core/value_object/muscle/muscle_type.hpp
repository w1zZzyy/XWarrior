#pragma once

#include <cstdint>

namespace core {
namespace value_object {

enum class MuscleType : uint8_t {
  // Chest
  kChestUpper,
  kChestLower,

  // Back
  kLatissimus,
  kTrapezius,
  kRhomboids,
  kErectorSpinae,

  // Shoulders
  kDeltoidFront,
  kDeltoidSide,
  kDeltoidRear,

  // Arms
  kBiceps,
  kTriceps,
  kForearms,

  // Core
  kAbs,
  kObliques,

  // Legs
  kGlutes,
  kQuadriceps,
  kHamstrings,
  kCalves
};

}  // namespace value_object
}  // namespace core