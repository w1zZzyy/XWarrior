#pragma once

#include "../../../../../common/progression.hpp"
#include "../../../../../value_object/muscle/muscle_type.hpp"

namespace core {
namespace model {

class Muscle;
using MuscleBuild = common::Progression<Muscle, value_object::MuscleType>;

class Muscle final : public MuscleBuild {
  friend MuscleBuild;
  Muscle() : MuscleBuild() {}
};

using MusclePtr = std::unique_ptr<Muscle>;

}  // namespace model
}  // namespace core