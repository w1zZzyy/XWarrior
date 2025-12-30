#pragma once

#include <concepts>
#include <type_traits>

namespace core {
namespace value_object {
namespace details {

template <typename T>
requires std::is_arithmetic_v<T>
class ID {
  T id_;

 public:
  ID() = default;
  constexpr ID(T id) noexcept : id_(id) {}
  constexpr T id() const noexcept { return id_; }
};

}  // namespace details
}  // namespace value_object
}  // namespace core