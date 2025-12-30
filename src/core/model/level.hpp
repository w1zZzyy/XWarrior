#pragma once

#include "../value_object/experience.hpp"
#include "../value_object/level/level_id.hpp"
#include "../value_object/level/level_type.hpp"
#include "../value_object/level/level_value.hpp"

#include <optional>

namespace core {
namespace model {

class Level {
  value_object::LevelID id_;
  value_object::LevelValue val_;
  value_object::LevelType type_;
  value_object::Experience required_exp_;
  Level(value_object::LevelID id, value_object::LevelValue val,
        value_object::LevelType type,
        value_object::Experience req_exp) noexcept;

 public:
  class Build {
   public:
    Build& setId(value_object::level_id id) noexcept;
    Build& setValue(value_object::level_value val) noexcept;
    Build& setType(value_object::LevelType type) noexcept;
    Build& setRequiredExp(value_object::experience_value exp) noexcept;
    std::optional<Level> build() const noexcept;

   private:
    std::optional<value_object::LevelID> id_;
    std::optional<value_object::LevelValue> val_;
    std::optional<value_object::LevelType> type_;
    std::optional<value_object::Experience> exp_;
  };

  constexpr bool canUpgrade(value_object::Experience exp) const noexcept {
    return exp.hasEnough(required_exp_);
  }
  constexpr value_object::LevelID id() const noexcept { return id_; }
  constexpr value_object::LevelValue value() const noexcept { return val_; }
  constexpr value_object::LevelType type() const noexcept { return type_; }
};

}  // namespace model
}  // namespace core