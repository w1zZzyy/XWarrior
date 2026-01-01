#pragma once

#include "../value_object/muscle/limb_type.hpp"
#include "../value_object/muscle/muscle_group_type.hpp"
#include "../value_object/muscle/muscle_type.hpp"

#include <optional>
#include <type_traits>

namespace core {
namespace common {

template <typename E>
concept EnumClass = std::is_enum_v<E>;

template <EnumClass E>
constexpr int ToIndex(E val) noexcept {
  return static_cast<int>(val);
}

constexpr std::optional<value_object::LimbType> LimbByMuscle(
    value_object::MuscleType muscle) noexcept {
  using MT = value_object::MuscleType;
  using LT = value_object::LimbType;

  switch (muscle) {
    case MT::kChestUpper:
    case MT::kChestLower:
    case MT::kLatissimus:
    case MT::kTrapezius:
    case MT::kRhomboids:
    case MT::kErectorSpinae:
    case MT::kAbs:
    case MT::kObliques:
      return LT::kTorso;

    case MT::kDeltoidFront:
    case MT::kDeltoidSide:
    case MT::kDeltoidRear:
    case MT::kBiceps:
    case MT::kTriceps:
    case MT::kForearms:
      return LT::kArms;

    case MT::kGlutes:
    case MT::kQuadriceps:
    case MT::kHamstrings:
    case MT::kCalves:
      return LT::kLegs;
  }

  return std::nullopt;
}

constexpr std::optional<value_object::LimbType> LimbByMuscleGroup(
    value_object::MuscleGroupType group) noexcept {
  using MG = value_object::MuscleGroupType;
  using LT = value_object::LimbType;

  switch (group) {
    case MG::kChest:
    case MG::kBack:
    case MG::kCore:
      return LT::kTorso;

    case MG::kShoulders:
    case MG::kArms:
      return LT::kArms;

    case MG::kLegs:
      return LT::kLegs;
  }

  return std::nullopt;
}

constexpr std::optional<value_object::MuscleGroupType> MuscleGroupByMuscle(
    value_object::MuscleType muscle) noexcept {
  using MT = value_object::MuscleType;
  using MG = value_object::MuscleGroupType;

  switch (muscle) {
    case MT::kChestUpper:
    case MT::kChestLower:
      return MG::kChest;

    case MT::kLatissimus:
    case MT::kTrapezius:
    case MT::kRhomboids:
    case MT::kErectorSpinae:
      return MG::kBack;

    case MT::kDeltoidFront:
    case MT::kDeltoidSide:
    case MT::kDeltoidRear:
      return MG::kShoulders;

    case MT::kBiceps:
    case MT::kTriceps:
    case MT::kForearms:
      return MG::kArms;

    case MT::kAbs:
    case MT::kObliques:
      return MG::kCore;

    case MT::kGlutes:
    case MT::kQuadriceps:
    case MT::kHamstrings:
    case MT::kCalves:
      return MG::kLegs;
  }

  return std::nullopt;
}

}  // namespace common
}  // namespace core