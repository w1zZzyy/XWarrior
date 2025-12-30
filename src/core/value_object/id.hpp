#pragma once

#include <type_traits>
#include <concepts>

namespace core {
namespace value_object {

template<typename T>
concept IDType = std::is_integral_v<T>;

template<IDType T>
class ID {
  T id_;

 public:
  ID() = default;
  constexpr ID(T id) noexcept : id_(id) {}
  constexpr T id() const noexcept { return id_; }
};

}  // namespace value_object
}  // namespace core