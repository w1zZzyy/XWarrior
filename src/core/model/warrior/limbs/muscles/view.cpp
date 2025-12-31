#include "view.hpp"

namespace core {
namespace model {

Muscle::Muscle(value_object::MuscleID id, value_object::MuscleType type,
               value_object::Experience exp,
               value_object::LevelValue level) noexcept
    : id_(id), type_(type), exp_(exp), level_(level) {}

Muscle::Build& Muscle::Build::setId(value_object::muscle_id id) noexcept {
  id_.emplace(id);
  return *this;
}

Muscle::Build& Muscle::Build::setType(value_object::MuscleType type) noexcept {
  type_.emplace(type);
  return *this;
}

Muscle::Build& Muscle::Build::setExp(
    value_object::experience_value exp) noexcept {
  exp_.emplace(exp);
  return *this;
}

Muscle::Build& Muscle::Build::setLevel(
    value_object::level_value level) noexcept {
  level_.emplace(level);
  return *this;
}

std::optional<Muscle> Muscle::Build::build() const noexcept {
  if (!id_ || !type_ || !exp_ || !level_) {
    return std::nullopt;
  }

  return Muscle(id_.value(), type_.value(), exp_.value(), level_->value());
}

}  // namespace model
}  // namespace core