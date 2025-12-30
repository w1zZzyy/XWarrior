#pragma once

#include <type_traits>
#include <concepts>

namespace core {
namespace value_object {
namespace details {

template<typename T>
requires std::is_arithmetic_v<T>
class GameCurrency {
 protected:
  T val_;

 public:
  GameCurrency() = default;
  constexpr GameCurrency(T val) noexcept : val_(val) {}
  constexpr bool hasEnough(const GameCurrency& val) const noexcept {
    return val_ >= val.val_;
  }
  constexpr GameCurrency& gain(T val) noexcept {
    val_ += val;
    return *this;
  }
  constexpr GameCurrency& decrease(T val) noexcept {
    val_ -= val;
    return *this;
  }
};

}
}  // namespace value_object
}  // namespace core