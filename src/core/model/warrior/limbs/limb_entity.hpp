#pragma once

#include "../../../value_object/muscle/limb_type.hpp"
#include "muscle_groups/muscle_group_entity.hpp"

#include <vector>

namespace core {
namespace model {

class Limb;
using LimbBuild = common::Progression<Limb, value_object::LimbType>;

class Limb final : public LimbBuild {
  std::vector<MuscleGroupPtr> muscle_groups_;

  friend LimbBuild;
  Limb() : LimbBuild() {}

 public:
  constexpr Limb& add(MuscleGroupPtr&& muscle_group) {
    muscle_groups_.emplace_back(std::move(muscle_group));
    return *this;
  }
  constexpr std::vector<MuscleGroupPtr>& muscle_groups() noexcept {
    return muscle_groups_;
  }
};

using LimbPtr = std::unique_ptr<Limb>;

}  // namespace model
}  // namespace core