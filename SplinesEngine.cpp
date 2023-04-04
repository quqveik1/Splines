#pragma once
#include "SplinesEngine.h"
#include <MainWindow.cpp>
#include <MultiLayCoordinatSystemWindow.cpp>
#include "SplineControl.cpp"

void SplinesEngine::onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    MainWindow* mainWnd = new MainWindow(this);
    setMainManager(mainWnd);

    SplineControl* coorSystem = new SplineControl(this);
    mainWnd->addWindow(coorSystem);


}