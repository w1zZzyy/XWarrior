#pragma once

#include "muscles/muscle_entity.hpp"

namespace core {
namespace model {

class MuscleGroup;
using MuscleGroupBuild =
    common::Progression<MuscleGroup, value_object::MuscleGroupType>;

class MuscleGroup final : public MuscleGroupBuild {
  MusclePtr muscles_[value_object::kMusclesCnt];

  friend MuscleGroupBuild;
  MuscleGroup() : MuscleGroupBuild() {}

 public:
  constexpr MuscleGroup& add(MusclePtr&& muscle) {
    int index = common::ToIndex(muscle->type());
    muscles_[index] = (std::move(muscle));
    return *this;
  }
  constexpr MusclePtr& getMuscle(value_object::MuscleType muscle) noexcept {
    int index = common::ToIndex(muscle);
    return muscles_[index];
  }
  constexpr const MusclePtr& getMuscle(value_object::MuscleType muscle) const noexcept {
    int index = common::ToIndex(muscle);
    return muscles_[index];
  }
};

using MuscleGroupPtr = common::derived_ptr<MuscleGroup>;

}  // namespace model
}  // namespace core