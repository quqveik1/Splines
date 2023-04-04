#pragma once
#include <MultiLayCoordinatSystemWindow.h>
#include "SplineArr.cpp"
#include <MessageButton.h>

struct SplineControl : MultiLayCoordinatSystemWindow
{
    SplineArr splineArr;
    COLORREF keyPointsColor = C_RED;
    size_t keyPointsLayIndex = 1;
    int keyPointsR = 5;
    double interPolDelta = 0.001;

    SplineControl(AbstractAppData* _app);

    void updateScreenPoints();
    void pushStartPoints();

    virtual void onClick(Vector mp) override;
    virtual void onMessageRecieve(const char* name, void* data) override;
};