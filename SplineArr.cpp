#pragma once
#include "SplineArr.h"
#include <cmath>

size_t SplineArr::size()
{
    return keyPoints.size();
}

Vector SplineArr::calcPoint(double dindex)
{
    int downIndex = floor(dindex);
    int upIndex = ceil(dindex);
    const double t = dindex - downIndex;
    const double t2 = t * t;
    const double t3 = t2 * t;
    Vector p0 = {};
    Vector p1 = {};
    Vector p2 = {};
    Vector p3 = {};

    if (downIndex >= 1)
    {
        p0 = (*this)[(size_t)downIndex - 1];
    }

    p1 = (*this)[(size_t)downIndex ];
    p2 = (*this)[(size_t)upIndex];
    if (upIndex < size() - 1)
    {
        p3 = (*this)[(size_t)upIndex + 1];
    }


    double a = -0.5f * p0.y + 1.5f * p1.y - 1.5f * p2.y + 0.5f * p3.y;
    double b = p0.y - 2.5f * p1.y + 2.0f * p2.y - 0.5f * p3.y;
    double c = -0.5f * p0.y + 0.5f * p2.y;
    double d = p1.y;

    return Vector(p1.x + t * (p2.x - p1.x), d + t * (c + t * (b + t * a)));
}

Vector& SplineArr::operator[](size_t index)
{
    if (index >= size()) {
        throw out_of_range("Index is out of range");
    }
    return keyPoints[index];
}
Vector& SplineArr::operator[](double dindex)
{
    if (dindex >= size() || dindex < 0) {
        throw out_of_range("Index is out of range");
    }
    Vector ans = calcPoint(dindex);
    return ans;
}

