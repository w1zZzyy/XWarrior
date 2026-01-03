#pragma once

#include "../../../common/events/queue.hpp"
#include "../../exercise/exercise_entity.hpp"
#include "limbs/limb_entity.hpp"

namespace core {
namespace model {

class Body final {
  std::optional<Limb> limbs_[value_object::kLimbsCnt];

 public:
  void addLimb(const Limb&) noexcept;
  void addMuscleGroup(const MuscleGroup&) noexcept;
  void addMuscle(const Muscle&) noexcept;
  void applyExercise(const Exercise&, common::event::Queue&);

 private:
  Limb* getLimb(value_object::LimbType) noexcept;
  Limb* getLimb(value_object::MuscleGroupType) noexcept;
  MuscleGroup* getMuscleGroup(value_object::MuscleGroupType) noexcept;
  MuscleGroup* getMuscleGroup(value_object::MuscleType) noexcept;
  Muscle* getMuscle(value_object::MuscleType) noexcept;
};

}  // namespace model
}  // namespace core