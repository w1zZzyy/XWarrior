#pragma once

#include "../../value_object/muscle/muscle_type.hpp"
#include "../../value_object/shared/mana.hpp"

namespace core {
namespace model {

class ExerciseValue {
  value_object::MuscleType muscle_;
  float intensity_;

 public:
  constexpr explicit ExerciseValue(value_object::MuscleType muscle,
                                   float intensity) noexcept
      : muscle_(muscle), intensity_(intensity) {}

  constexpr auto muscle() const noexcept { return muscle_; }

  constexpr value_object::Experience computeExp(
      value_object::Mana mana) const noexcept {
    return mana.to_experience(intensity_);
  }
};

}  // namespace model
}  // namespace core