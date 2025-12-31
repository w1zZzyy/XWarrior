#pragma once

#include "../../../../value_object/level/level_value.hpp"
#include "../../../../value_object/muscle/muscle_id.hpp"
#include "../../../../value_object/muscle/muscle_type.hpp"
#include "../../../../value_object/shared/experience.hpp"

#include <optional>

namespace core {
namespace model {

class Muscle {
  value_object::MuscleID id_;
  value_object::MuscleType type_;
  value_object::Experience exp_;
  value_object::LevelValue level_;
  Muscle(value_object::MuscleID id, value_object::MuscleType type,
         value_object::Experience exp, value_object::LevelValue level) noexcept;

 public:
  class Build {
    std::optional<value_object::MuscleID> id_;
    std::optional<value_object::MuscleType> type_;
    std::optional<value_object::Experience> exp_;
    std::optional<value_object::LevelValue> level_;

   public:
    Build& setId(value_object::muscle_id id) noexcept;
    Build& setType(value_object::MuscleType type) noexcept;
    Build& setExp(value_object::experience_value exp) noexcept;
    Build& setLevel(value_object::level_value level) noexcept;
    std::optional<Muscle> build() const noexcept;
  };
};

}  // namespace model
}  // namespace core