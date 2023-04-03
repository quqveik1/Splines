#pragma once
#include <Window.h>
#include "SplineArr.cpp"

struct SplineControl : Window
{
    SplineArr splineArr;

    SplineControl(AbstractAppData* _app);

    virtual void onMessageRecieve(const char* name, void* data);
};