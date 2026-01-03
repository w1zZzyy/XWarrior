#include "body_entity.hpp"

#include "../events/exp_gained.hpp"
#include "../events/level_upgraded.hpp"

#include <stdexcept>

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

template <typename BodyPart>
void applyExercise(BodyPart* part, auto exp, common::event::Queue& q) {
  part->gainExp(exp);
  q.create_event<ExpGainedEvent<BodyPart>>(part, exp);

  if (std::optional<Level> oldLvl = part->upgradeLvl()) {
    q.create_event<LevelUpgradedEvent<BodyPart>>(part, oldLvl->value(),
                                                 part->level());
  }
}

void Body::applyExercise(const Exercise& exercise, common::event::Queue& q) {
  const Mana mana = exercise.mana();
  for (const ExerciseValue& val : exercise) {
    const auto exp = val.computeExp(mana).get();
    const MuscleType muscle_t = val.muscle();

    const auto group_t = MuscleGroupByMuscle(muscle_t);
    if (!group_t) throw std::runtime_error("could not find group");

    const auto limb_t = LimbByMuscleGroup(group_t.value());
    if (!limb_t) throw std::runtime_error("could not find limb");

    Muscle* muscle = getMuscle(muscle_t);
    MuscleGroup* group = getMuscleGroup(group_t.value());
    Limb* limb = getLimb(limb_t.value());

    if (!muscle || !group || !limb)
      throw std::runtime_error("could not find boyd part");

    applyExercise<Muscle>(muscle, exp, q);
    applyExercise<MuscleGroup>(group, exp, q);
    applyExercise<Limb>(limb, exp, q);
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