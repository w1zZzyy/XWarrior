#include "muscle_group_entity.hpp"

namespace core {
namespace model {

using namespace value_object;
using namespace common;

void MuscleGroup::addMuscle(MusclePtr&& muscle) noexcept {
    MuscleType type = muscle->type();
    int index = common::ToIndex(type);
    muscles_[index] = (std::move(muscle));
}

MusclePtr MuscleGroup::getMuscle(value_object::MuscleType muscle) const noexcept {
    int index = common::ToIndex(muscle);
    return muscles_[index];
}

}
}