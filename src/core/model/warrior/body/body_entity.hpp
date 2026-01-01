#pragma once

#include "limbs/limb_entity.hpp"

namespace core {
namespace model {

class Body final {
  LimbPtr limbs_[value_object::kLimbsCnt];

 public:
  void addLimb(LimbPtr&&) noexcept;
  void addMuscleGroup(MuscleGroupPtr&&) noexcept;
  void addMuscle(MusclePtr&&) noexcept;

 private:
  LimbPtr getLimb(value_object::LimbType) const noexcept;
  LimbPtr getLimb(value_object::MuscleGroupType) const noexcept;
  MuscleGroupPtr getMuscleGroup(value_object::MuscleGroupType) const noexcept;
  MuscleGroupPtr getMuscleGroup(value_object::MuscleType) const noexcept;
  MusclePtr getMuscle(value_object::MuscleType) const noexcept;
};

}  // namespace model
}  // namespace core