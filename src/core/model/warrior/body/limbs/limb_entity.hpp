#pragma once

#include "muscle_groups/muscle_group_entity.hpp"

namespace core {
namespace model {

class Limb;
using LimbBuild = common::Progression<Limb, value_object::LimbType>;

class Limb final : public LimbBuild {
  std::optional<MuscleGroup> muscle_groups_[value_object::kMuscleGroupsCnt];

  friend LimbBuild;
  Limb() : LimbBuild() {}

 public:
  void addMuscleGroup(const MuscleGroup&) noexcept;
  const MuscleGroup* getMuscleGroup(
      value_object::MuscleGroupType) const noexcept;
  MuscleGroup* getMuscleGroup(value_object::MuscleGroupType) noexcept;
};

}  // namespace model
}  // namespace core