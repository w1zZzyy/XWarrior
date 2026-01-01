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
  void addMuscle(MusclePtr&&) noexcept;
  MusclePtr getMuscle(value_object::MuscleType) const noexcept;
};

using MuscleGroupPtr = common::derived_ptr<MuscleGroup>;

}  // namespace model
}  // namespace core