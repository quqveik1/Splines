#pragma once
#include "SplineControl.h"
#include <MessageButton.cpp>
#include <Window.cpp>

SplineControl::SplineControl(AbstractAppData* _app) :
    MultiLayCoordinatSystemWindow(_app),
    splineArr()
{
    setMatchParent(true);
    setCCells({ 100, 100 });

    pushStartPoints();
    
    addLay();
    
    updateScreenPoints();
};

void SplineControl::pushStartPoints()
{
    splineArr.sortedPush({ 0, 0 });
    splineArr.sortedPush(cCells);
}

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

void SplineControl::onMessageRecieve(const char* name, void* data)
{
    splineArr.clear();
    pushStartPoints();
    updateScreenPoints();
}