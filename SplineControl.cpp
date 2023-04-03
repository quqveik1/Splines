#pragma once
#include "SplineControl.h"
#include <Window.cpp>

SplineControl::SplineControl(AbstractAppData* _app) :
    Window(_app),
    splineArr()
{
};

void SplineControl::onMessageRecieve(const char* name, void* data)
{
}