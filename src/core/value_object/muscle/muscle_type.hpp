#pragma once

#include <cstdint>

namespace core {
namespace value_object {

enum class MuscleType : uint8_t {
  kChest,
  kBack,
  kShoulders,
  kBiceps,
  kTriceps,
  kForearms,

  kAbs,
  kObliques,
  kLowerBack,

  kGlutes,
  kQuadriceps,
  kHamstrings,
  kCalves
};

}  // namespace value_object
}  // namespace core