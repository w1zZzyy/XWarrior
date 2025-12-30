#pragma once

#include "../details/game_currency.hpp"

#include <cstdint>

namespace core {
namespace value_object {

using coins_t = uint32_t;
using Coins = details::GameCurrency<coins_t>;

}  // namespace value_object
}  // namespace core