#include "body_entity.hpp"

namespace core {
namespace model {

using namespace value_object;
using namespace common;

void Body::addLimb(const Limb& limb) noexcept {
  LimbType type = limb.type();
  int index = ToIndex(type);
  limbs_[index] = std::move(limb);
}

void Body::addMuscleGroup(const MuscleGroup& muscle_group) noexcept {
  if (Limb* limb = getLimb(muscle_group.type())) {
    limb->addMuscleGroup(std::move(muscle_group));
  }
}

void Body::addMuscle(const Muscle& muscle) noexcept {
  if (MuscleGroup* muscle_group = getMuscleGroup(muscle.type())) {
    muscle_group->addMuscle(std::move(muscle));
  }
}

Limb* Body::getLimb(value_object::LimbType limb) noexcept {
  int index = ToIndex(limb);
  if (limbs_[index]) return &limbs_[index].value();
  return nullptr;
}

Limb* Body::getLimb(value_object::MuscleGroupType muscle_group) noexcept {
  if (auto limb_type = LimbByMuscleGroup(muscle_group)) {
    return getLimb(limb_type.value());
  }
  return nullptr;
}

MuscleGroup* Body::getMuscleGroup(
    value_object::MuscleGroupType muscle_group) noexcept {
  if (Limb* ptr = getLimb(muscle_group))
    return ptr->getMuscleGroup(muscle_group);
  return nullptr;
}

MuscleGroup* Body::getMuscleGroup(value_object::MuscleType muscle) noexcept {
  if (auto muscle_group = MuscleGroupByMuscle(muscle)) {
    return getMuscleGroup(muscle_group.value());
  }
  return nullptr;
}

Muscle* Body::getMuscle(value_object::MuscleType muscle) noexcept {
  if (auto muscle_group_type = MuscleGroupByMuscle(muscle)) {
    if (MuscleGroup* ptr = getMuscleGroup(muscle_group_type.value()))
      return ptr->getMuscle(muscle);
  }
  return nullptr;
}

}  // namespace model
}  // namespace core