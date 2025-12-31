#pragma once

#include <cstdint>

namespace core {
namespace value_object {

enum class MuscleGroupType : uint8_t {
  kChest,
  kBack,
  kShoulders,
  kArms,
  kCore,
  kLegs
};

}  // namespace value_object
}  // namespace core
