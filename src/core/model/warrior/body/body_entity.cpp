#include "body_entity.hpp"

namespace core {
namespace model {

using namespace value_object;
using namespace common;

void Body::addLimb(LimbPtr&& limb) noexcept {
  LimbType type = limb->type();
  int index = ToIndex(type);
  limbs_[index] = std::move(limb);
}

void Body::addMuscleGroup(MuscleGroupPtr&& muscle_group) noexcept {
  if (LimbPtr limb = getLimb(muscle_group->type())) {
    limb->addMuscleGroup(std::move(muscle_group));
  }
}

void Body::addMuscle(MusclePtr&& muscle) noexcept {
  if (MuscleGroupPtr muscle_group = getMuscleGroup(muscle->type())) {
    muscle_group->addMuscle(std::move(muscle));
  }
}

LimbPtr Body::getLimb(value_object::LimbType limb) const noexcept {
  int index = ToIndex(limb);
  return limbs_[index];
}

LimbPtr Body::getLimb(
    value_object::MuscleGroupType muscle_group) const noexcept {
  if (auto limb_type = LimbByMuscleGroup(muscle_group)) {
    return getLimb(limb_type.value());
  }
  return nullptr;
}

MuscleGroupPtr Body::getMuscleGroup(
    value_object::MuscleGroupType muscle_group) const noexcept {
  if (LimbPtr ptr = getLimb(muscle_group))
    return ptr->getMuscleGroup(muscle_group);
  return nullptr;
}

MuscleGroupPtr Body::getMuscleGroup(
    value_object::MuscleType muscle) const noexcept {
  if (auto muscle_group = MuscleGroupByMuscle(muscle)) {
    return getMuscleGroup(muscle_group.value());
  }
  return nullptr;
}

MusclePtr Body::getMuscle(value_object::MuscleType muscle) const noexcept {
  if (auto muscle_group_type = MuscleGroupByMuscle(muscle)) {
    if (MuscleGroupPtr ptr = getMuscleGroup(muscle_group_type.value()))
      return ptr->getMuscle(muscle);
  }
  return nullptr;
}

}  // namespace model
}  // namespace core