#pragma once
#include "SplineArr.h"
#include <cmath>
#include <iterator>
#include <limits>


size_t SplineArr::size() const
{
    return keyPoints.size();
}

void SplineArr::push(Vector point)
{
    keyPoints.push_back(point);
}

struct CustomVectorXComparator {
    bool operator()(const Vector& a, const Vector& b) const {
        return isSmaller(a.x, b.x);
    }
};

size_t SplineArr::sortedPush(Vector point)
{
    size_t insertPos = 0;
    size_t currPos = 0;
    size_t len = size();
    if (len == 0)
    {
        push(point);
        return len;
    }

    if (len > 0)
    {
        if (point.x > keyPoints[len - 1].x)
        {
            push(point);
            return len;
        }
    }

    CustomVectorXComparator comparator;
    std::vector<Vector>::iterator positionIt = std::lower_bound(keyPoints.begin(), keyPoints.end(), point, comparator);
    size_t arrPos = distance(keyPoints.begin(), positionIt);
    if (arrPos <= len)
    {
        keyPoints.insert(positionIt, point);
        return arrPos;
    }

    return SIZE_MAX;
}

void SplineArr::sort()
{
    CustomVectorXComparator comparator;
    std::sort(keyPoints.begin(), keyPoints.end(), comparator);
}

void SplineArr::clear()
{
    keyPoints.clear();
}

Vector SplineArr::calcPoint(double dindex)
{
    size_t downIndex = (size_t)floor(dindex);
    size_t upIndex = (size_t)ceil(dindex);
    const double t = dindex - downIndex;
    const double t2 = t * t;
    const double t3 = t2 * t;
    Vector p0 = {};
    Vector p1 = {};
    Vector p2 = {};
    Vector p3 = {};

    

    p1 = (*this)[downIndex];
    p2 = (*this)[upIndex];

    if (downIndex < 1)
    {
        p0 = p1;
    }
    else
    {
        p0 = (*this)[downIndex - 1];
    }

    if (upIndex + 1 >= size())
    {
        p3 = p2;
    }
    else
    {
        p3 = (*this)[upIndex + 1];
    }


    double a = -0.5f * p0.y + 1.5f * p1.y - 1.5f * p2.y + 0.5f * p3.y;
    double b = p0.y - 2.5f * p1.y + 2.0f * p2.y - 0.5f * p3.y;
    double c = -0.5f * p0.y + 0.5f * p2.y;
    double d = p1.y;

    return Vector(p1.x + t * (p2.x - p1.x), d + t * (c + t * (b + t * a)));
}

Vector& SplineArr::operator[](size_t index)
{
    size_t keyPointSize = size();
    if (index >= keyPointSize)
    {
        throw out_of_range("Index is out of range");
    }
    return keyPoints[index];
}
Vector SplineArr::operator[](double dindex)
{
    size_t currLen = size();
    if (isBigger (dindex + 1, (double)currLen) || isSmaller (dindex, 0))
    {
        throw out_of_range("Index is out of range");
    }
    Vector ans = calcPoint(dindex);
    return ans;
}

