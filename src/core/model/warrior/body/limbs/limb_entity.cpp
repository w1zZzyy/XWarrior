#include "limb_entity.hpp"

namespace core {
namespace model {

using namespace value_object;
using namespace common;

void Limb::addMuscleGroup(const MuscleGroup& muscle_group) noexcept {
  MuscleGroupType type = muscle_group.type();
  int index = ToIndex(type);
  muscle_groups_[index] = muscle_group;
}

const MuscleGroup* Limb::getMuscleGroup(
    value_object::MuscleGroupType muscle_group) const noexcept {
  int index = common::ToIndex(muscle_group);
  if (muscle_groups_[index]) return &muscle_groups_[index].value();
  return nullptr;
}

MuscleGroup* Limb::getMuscleGroup(
    value_object::MuscleGroupType muscle_group) noexcept {
  int index = common::ToIndex(muscle_group);
  if (muscle_groups_[index]) return &muscle_groups_[index].value();
  return nullptr;
}

}  // namespace model
}  // namespace core