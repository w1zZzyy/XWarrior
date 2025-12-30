#pragma once

#include <type_traits>
#include <concepts>

namespace core {
namespace value_object {
namespace details {

template<typename T>
requires std::is_arithmetic_v<T>
class ID {
  T id_;

 public:
  ID() = default;
  constexpr ID(T id) noexcept : id_(id) {}
  constexpr T id() const noexcept { return id_; }
};

}
}  // namespace value_object
}  // namespace core