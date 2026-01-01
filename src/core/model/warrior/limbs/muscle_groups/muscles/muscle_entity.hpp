#pragma once

#include "../../../../../common/progression.hpp"
#include "../../../../../common/types.hpp"

namespace core {
namespace model {

class Muscle;
using MuscleBuild = common::Progression<Muscle, value_object::MuscleType>;

class Muscle final : public MuscleBuild {
  friend MuscleBuild;
  Muscle() : MuscleBuild() {}
};

using MusclePtr = common::derived_ptr<Muscle>;

}  // namespace model
}  // namespace core