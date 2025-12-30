#pragma once

#include <chrono>

namespace core {
namespace value_object {

using time_point_t = std::chrono::system_clock::time_point;
using unix_timestamp_t = std::int64_t;

class TimePoint {
    time_point_t tp_;

public:
    TimePoint() = default;

    constexpr explicit TimePoint(time_point_t tp) noexcept : tp_(tp) {}

    explicit TimePoint(unix_timestamp_t timestamp_sec) noexcept
        : tp_(std::chrono::system_clock::time_point{
              std::chrono::seconds{timestamp_sec}}) {}

    inline static TimePoint Now() noexcept {
        return TimePoint{std::chrono::system_clock::now()};
    }

    constexpr unix_timestamp_t utc() const noexcept {
        return std::chrono::duration_cast<std::chrono::seconds>(
                   tp_.time_since_epoch())
            .count();
    }

    constexpr time_point_t tp() const noexcept { return tp_; }
};

}  // namespace value_object
}  // namespace core
