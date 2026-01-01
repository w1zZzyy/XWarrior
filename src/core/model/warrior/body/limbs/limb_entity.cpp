#include "limb_entity.hpp"

namespace core {
namespace model {

using namespace value_object;
using namespace common;

void Limb::addMuscleGroup(MuscleGroupPtr&& muscle_group) noexcept {
    MuscleGroupType type = muscle_group->type();
    int index = ToIndex(type);
    muscle_groups_[index] = (std::move(muscle_group));
}

MuscleGroupPtr Limb::getMuscleGroup(value_object::MuscleGroupType muscle_group) const noexcept {
    int index = common::ToIndex(muscle_group);
    return muscle_groups_[index];
}

}
}