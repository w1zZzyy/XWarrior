#pragma once

#include "../details/id.hpp"

#include <cstdint>

namespace core {
namespace value_object {

using user_id = uint32_t;
using UserID = details::ID<user_id>;

}  // namespace value_object
}  // namespace core