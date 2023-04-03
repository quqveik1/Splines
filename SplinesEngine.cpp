#pragma once
#include "SplinesEngine.h"
#include <MainWindow.cpp>
#include <MultiLayCoordinatSystemWindow.cpp>
#include "SplineControl.cpp"

void SplinesEngine::onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    MainWindow* mainWnd = new MainWindow(this);
    setMainManager(mainWnd);

    MultiLayCoordinatSystemWindow* coorSystem = new MultiLayCoordinatSystemWindow(this);
    coorSystem->setMatchParent(true);
    coorSystem->setCCells({ 100, 100 });
    mainWnd->addWindow(coorSystem);


}