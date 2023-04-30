#pragma once
#include "SplinesEngine.h"
#include <MainWindow.cpp>
#include <MultiLayCoordinatSystemWindow.cpp>
#include "SplineControl.cpp"
#include "resource.h"

void SplinesEngine::onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    MainWindow* mainWnd = new MainWindow(this);
    setMainManager(mainWnd);

    SplineControl* coorSystem = new SplineControl(this);
    mainWnd->addWindow(coorSystem);

    MessageButton* clearButton = new MessageButton(this);
    clearButton->setText("Очистить");
    clearButton->setReciever(coorSystem);
    clearButton->setWrapStatus(true);
    clearButton->setColor(C_TRANSPARENT);
    clearButton->setTrancparencyOutput(true); 
    mainWnd->addWindow(clearButton);
}

void SplinesEngine::setWindowParameters(HINSTANCE hInstance)
{
    AbstractAppData::setWindowParameters(hInstance);
    loadAndSetIcon(IDI_ICON2);
}