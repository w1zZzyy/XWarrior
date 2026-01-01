#pragma once

#include "../value_object/level/level_value.hpp"
#include "../value_object/shared/experience.hpp"

#include <memory>
#include <optional>

namespace core {
namespace common {

template<typename Derived>
using derived_ptr = std::unique_ptr<Derived>;

template <typename Derived, typename EnumType>
class Progression {
 protected:
  EnumType type_;
  value_object::LevelValue level_;
  value_object::Experience exp_;
  Progression() = default;

 public:
  virtual ~Progression() = default;

  constexpr EnumType type() const noexcept { return type_; }
  constexpr value_object::LevelValue level() const noexcept { return level_; }
  constexpr value_object::Experience exp() const noexcept { return exp_; }

  class Build {
    std::optional<EnumType> type_;
    std::optional<value_object::Experience> exp_;
    std::optional<value_object::LevelValue> level_;

   public:
    constexpr Build& setType(EnumType type) noexcept {
      type_ = type;
      return *this;
    }
    constexpr Build& setExp(value_object::experience_value exp) noexcept {
      exp_.emplace(exp);
      return *this;
    }
    constexpr Build& setLevel(value_object::level_value level) noexcept {
      level_.emplace(level);
      return *this;
    }
    constexpr derived_ptr<Derived> build() const noexcept {
      if (!type_ || !exp_ || !level_) {
        return nullptr;
      }
      derived_ptr<Derived> d(new Derived());
      d->type_ = type_.value();
      d->exp_ = exp_.value();
      d->level_ = level_.value();
      return d;
    }
  };
};

}  // namespace common
}  // namespace core