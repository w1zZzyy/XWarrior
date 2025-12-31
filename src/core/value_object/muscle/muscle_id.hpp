#pragma once

#include "../details/id.hpp"

#include <cstdint>

namespace core {
namespace value_object {

using muscle_id = uint16_t;
using MuscleID = details::ID<muscle_id>;

}  // namespace value_object
}  // namespace core