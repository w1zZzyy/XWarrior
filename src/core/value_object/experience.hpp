#pragma once

#include <cstdint>

namespace core {
namespace value_object {

using experience_value = uint32_t;

class Experience {
  experience_value exp_;

 public:
  Experience() = default;
  constexpr Experience(experience_value exp) noexcept : exp_(exp) {}
  constexpr bool hasEnough(const Experience& exp) const noexcept {
    return exp_ >= exp.exp_;
  }
};

}  // namespace value_object
}  // namespace core