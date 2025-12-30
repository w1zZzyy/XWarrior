#pragma once

#include "../details/game_currency.hpp"

#include <cstdint>

namespace core {
namespace value_object {

using experience_value = uint32_t;
using Experience = details::GameCurrency<experience_value>;

}  // namespace value_object
}  // namespace core