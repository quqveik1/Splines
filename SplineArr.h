#pragma once
#include <Q_Vector.h>
#include <vector>
#include <stdexcept>

using namespace std;

struct SplineArr
{
    vector<Vector> keyPoints;

    Vector calcPoint(double dindex);

    size_t size();
    Vector& operator[](size_t index);
    Vector& operator[](double dindex);

};