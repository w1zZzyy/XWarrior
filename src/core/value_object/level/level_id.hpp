#pragma once

#include "../details/id.hpp"

#include <cstdint>

namespace core {
namespace value_object {

using level_id = uint8_t;
using LevelID = details::ID<level_id>;

}  // namespace value_object
}  // namespace core