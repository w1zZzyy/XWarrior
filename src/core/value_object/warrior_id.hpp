#pragma once

#include "id.hpp"

#include <cstdint>

namespace core {
namespace value_object {

using warrior_id = uint32_t;
using WarriorID = ID<warrior_id>;

}  // namespace value_object
}  // namespace core