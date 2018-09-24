#pragma once

// clamps val between min and max
template <typename T>
inline T clamp(T val, T min, T max)
{
    return (val >= min) ?
           ((val <= max) ? val : max) : min;
}
