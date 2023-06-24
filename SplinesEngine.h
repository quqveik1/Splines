#pragma once

#include <AbstractApp.cpp>
struct SplinesEngine : AbstractAppData
{
    SplinesEngine();
    virtual void onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
    virtual void setWindowParameters(HINSTANCE hInstance);
};