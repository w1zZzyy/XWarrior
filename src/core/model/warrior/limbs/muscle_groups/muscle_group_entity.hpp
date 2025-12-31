#pragma once

#include "../../../../value_object/muscle/muscle_group_type.hpp"
#include "muscles/muscle_entity.hpp"

#include <vector>

namespace core {
namespace model {

class MuscleGroup;
using MuscleGroupBuild =
    common::Progression<MuscleGroup, value_object::MuscleGroupType>;

class MuscleGroup final : public MuscleGroupBuild {
  std::vector<MusclePtr> muscles_;

  friend MuscleGroupBuild;
  MuscleGroup() : MuscleGroupBuild() {}

 public:
  constexpr MuscleGroup& add(MusclePtr&& muscle) {
    muscles_.emplace_back(std::move(muscle));
    return *this;
  }
  constexpr std::vector<MusclePtr>& muscles() noexcept { return muscles_; }
};

using MuscleGroupPtr = std::unique_ptr<MuscleGroup>;

}  // namespace model
}  // namespace core