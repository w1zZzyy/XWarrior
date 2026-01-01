#pragma once

#include "muscle_groups/muscle_group_entity.hpp"

namespace core {
namespace model {

class Limb;
using LimbBuild = common::Progression<Limb, value_object::LimbType>;

class Limb final : public LimbBuild {
  MuscleGroupPtr muscle_groups_[value_object::kMuscleGroupsCnt];

  friend LimbBuild;
  Limb() : LimbBuild() {}

 public:
  constexpr Limb& add(MuscleGroupPtr&& muscle_group) noexcept {
    int index = common::ToIndex(muscle_group->type());
    muscle_groups_[index] = (std::move(muscle_group));
    return *this;
  }

  constexpr MuscleGroupPtr& getMuscleGroup(value_object::MuscleGroupType muscle_group) noexcept {
    int index = common::ToIndex(muscle_group);
    return muscle_groups_[index];
  } 

  constexpr const MuscleGroupPtr& getMuscleGroup(value_object::MuscleGroupType muscle_group) const noexcept {
    int index = common::ToIndex(muscle_group);
    return muscle_groups_[index];
  } 

};

using LimbPtr = common::derived_ptr<Limb>;

}  // namespace model
}  // namespace core