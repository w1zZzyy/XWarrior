#pragma once

#include "../model/level/level_entity.hpp"
#include "../value_object/shared/experience.hpp"

#include <memory>
#include <optional>

namespace core {
namespace common {

template <typename Derived, typename EnumType>
class Progression {
 protected:
  using Level = model::Level;
  using Exp = value_object::Experience;

  EnumType type_;
  Level level_;
  Exp exp_;

  Progression() = default;

 public:
  virtual ~Progression() = default;

  constexpr EnumType type() const noexcept { return type_; }
  constexpr Level level() const noexcept { return level_; }
  constexpr Exp exp() const noexcept { return exp_; }

  class Build {
    std::optional<EnumType> type_;
    std::optional<Exp> exp_;
    std::optional<Level> level_;

   public:
    constexpr Build& setType(EnumType type) noexcept {
      type_ = type;
      return *this;
    }
    constexpr Build& setExp(Exp exp) noexcept {
      exp_.emplace(exp);
      return *this;
    }
    constexpr Build& setLevel(Level level) noexcept {
      level_.emplace(level);
      return *this;
    }
    constexpr std::optional<Derived> build() const noexcept {
      if (!type_ || !exp_ || !level_) {
        return std::nullopt;
      }
      Derived d;
      d.type_ = type_.value();
      d.exp_ = exp_.value();
      d.level_ = level_.value();
      return d;
    }
  };
};

}  // namespace common
}  // namespace core