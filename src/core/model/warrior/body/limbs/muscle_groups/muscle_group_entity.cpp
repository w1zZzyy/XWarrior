#include "muscle_group_entity.hpp"

namespace core {
namespace model {

using namespace value_object;
using namespace common;

void MuscleGroup::addMuscle(const Muscle& muscle) noexcept {
  MuscleType type = muscle.type();
  int index = common::ToIndex(type);
  muscles_[index] = muscle;
}

const Muscle* MuscleGroup::getMuscle(
    value_object::MuscleType muscle) const noexcept {
  int index = common::ToIndex(muscle);
  if (muscles_[index]) return &muscles_[index].value();
  return nullptr;
}

Muscle* MuscleGroup::getMuscle(value_object::MuscleType muscle) noexcept {
  int index = common::ToIndex(muscle);
  if (muscles_[index]) return &muscles_[index].value();
  return nullptr;
}

}  // namespace model
}  // namespace core