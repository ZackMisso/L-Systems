#pragma once

#include <lsys/common.h>
#include <lsys/datastructures/vector.h>

struct PathData
{
    PathData(Vec2<float> p, Vec2<float> d);

    Vec2<float> pos;
    Vec2<float> dir;
};
