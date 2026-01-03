#pragma once

#include "muscles/muscle_entity.hpp"

namespace core {
namespace model {

class MuscleGroup;
using MuscleGroupBuild =
    common::Progression<MuscleGroup, value_object::MuscleGroupType>;

class MuscleGroup final : public MuscleGroupBuild {
  std::optional<Muscle> muscles_[value_object::kMusclesCnt];

  friend MuscleGroupBuild;
  MuscleGroup() : MuscleGroupBuild() {}

 public:
  MuscleGroup(const MuscleGroup&) = default;
  MuscleGroup& operator=(const MuscleGroup&) = default;
  void addMuscle(const Muscle&) noexcept;
  const Muscle* getMuscle(value_object::MuscleType) const noexcept;
  Muscle* getMuscle(value_object::MuscleType) noexcept;
};

}  // namespace model
}  // namespace core