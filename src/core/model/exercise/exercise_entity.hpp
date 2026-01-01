#pragma once

#include "value.hpp"

#include <vector>

namespace core {
namespace model {

class Exercise {
  value_object::Mana mana_;
  std::vector<ExerciseValue> values_;

 public:
  explicit Exercise(value_object::mana_value mana) : mana_(mana) {}
  void addValue(ExerciseValue val) { values_.push_back(val); }
  constexpr auto mana() const noexcept { return mana_; }
  auto begin() const noexcept { return values_.cbegin(); }
  auto end() const noexcept { return values_.cend(); }
};

}  // namespace model
}  // namespace core