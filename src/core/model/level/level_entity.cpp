#include "level_entity.hpp"

namespace core {
namespace model {

Level::Level(value_object::LevelID id, value_object::LevelValue val,
             value_object::LevelType type,
             value_object::Experience req_exp) noexcept
    : id_(id), val_(val), type_(type), required_exp_(req_exp) {}

Level::Build& Level::Build::setId(value_object::level_id id) noexcept {
  id_.emplace(id);
  return *this;
}

Level::Build& Level::Build::setValue(value_object::level_value val) noexcept {
  val_.emplace(val);
  return *this;
}

Level::Build& Level::Build::setType(value_object::LevelType type) noexcept {
  type_.emplace(type);
  return *this;
}

Level::Build& Level::Build::setRequiredExp(
    value_object::experience_value exp) noexcept {
  exp_.emplace(exp);
  return *this;
}

std::optional<Level> Level::Build::build() const noexcept {
  if (!id_ || !val_ || !type_ || !exp_) {
    return std::nullopt;
  }
  return Level(id_.value(), val_.value(), type_.value(), exp_.value());
}

}  // namespace model
}  // namespace core