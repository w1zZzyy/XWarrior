#pragma once

#include <cstdint>

namespace core {
namespace value_object {

enum class LimbType : uint8_t { kHead, kTorso, kArms, kLegs };
constexpr uint8_t kLimbsCnt = 4;

}  // namespace value_object
}  // namespace core