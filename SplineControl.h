#pragma once
#include <MultiLayCoordinatSystemWindow.h>
#include "SplineArr.cpp"

struct SplineControl : MultiLayCoordinatSystemWindow
{
    SplineArr splineArr;
    COLORREF keyPointsColor = C_RED;
    size_t keyPointsLayIndex = 1;
    int keyPointsR = 5;
    double interPolDelta = 0.001;

    SplineControl(AbstractAppData* _app);

    void updateScreenPoints();

    virtual void onClick(Vector mp) override;
};