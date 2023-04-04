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
    void push(Vector point);
    size_t sortedPush(Vector point);
    void sort();
    Vector& operator[](size_t index);
    Vector& operator[](double dindex);

};