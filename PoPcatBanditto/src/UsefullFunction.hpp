#pragma once

#include <Windows.h>

int getScreenFrameRate()
{
    HDC hDCScreen = GetDC(NULL);
    int RefreshFrequency = GetDeviceCaps(hDCScreen, VREFRESH);
    ReleaseDC(NULL, hDCScreen);

    return RefreshFrequency;
}