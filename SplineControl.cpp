#pragma once
#include "SplineControl.h"
#include <Window.cpp>

SplineControl::SplineControl(AbstractAppData* _app) :
    MultiLayCoordinatSystemWindow(_app),
    splineArr()
{
    setMatchParent(true);
    setCCells({ 100, 100 });

    splineArr.sortedPush({ 0, 0 });
    splineArr.sortedPush(cCells);
    
    updateScreenPoints();

    addLay();
};

void SplineControl::updateScreenPoints()
{
    clearSys();
    size_t keyPointSplineLen = splineArr.size();
    for (double i = 0; i < keyPointSplineLen - 1; i += interPolDelta)
    {
        addPoint(splineArr[i]);
    }

    for (Vector _keyPoint : splineArr.keyPoints)
    {
        addPoint(_keyPoint, keyPointsColor, keyPointsR, keyPointsLayIndex);
    }
}


void SplineControl::onClick(Vector mp)
{
    MultiLayCoordinatSystemWindow::onClick(mp);
    Vector coorPoint = fromPixToCell(mp);
    splineArr.sortedPush(coorPoint);
    updateScreenPoints();
}