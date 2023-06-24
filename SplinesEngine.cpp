#pragma once
#include "SplinesEngine.h"
#include <MainWindow.cpp>
#include <MultiLayCoordinatSystemWindow.cpp>
#include "SplineControl.cpp"
#include "resource.h"

SplinesEngine::SplinesEngine() :
    AbstractAppData(NULL, "..\\TESTWIN32_GRAPHICAPP\\x64\\Release")
{
}

void SplinesEngine::onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    MainWindow* mainWnd = new MainWindow(this);
    setMainManager(mainWnd);

    SplineControl* coorSystem = new SplineControl(this);
    mainWnd->addWindow(coorSystem);

    getStringResources().addCResource(StringResources::Russian, "clean", "Очистить");
    getStringResources().addCResource(StringResources::English, "clean", "Clean");

    MessageButton* clearButton = new MessageButton(this);
    clearButton->setText(getStringResources().getCResource("clean"));
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

    getStringResources().addResource(StringResources::Russian, "splines", "Сплайны");
    getStringResources().addResource(StringResources::English, "splines", "Splines");
    std::string title = setAppInfoToString(getStringResources().getResource("splines"));

    setAppName(title);
}