#pragma once

#include "../../../../../../common/events/queue.hpp"
#include "../../../../../../common/progression.hpp"
#include "../../../../../../common/types.hpp"

namespace core {
namespace model {

class Muscle;
using MuscleBuild = common::Progression<Muscle, value_object::MuscleType>;

class Muscle final : public MuscleBuild {
  friend MuscleBuild;
  Muscle() : MuscleBuild() {}

 public:
  Muscle(const Muscle&) = default;
  Muscle& operator=(const Muscle&) = default;
};

}  // namespace model
}  // namespace core