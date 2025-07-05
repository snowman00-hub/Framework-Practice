#include "stdafx.h"
#include "Framework.h"

int main()
{
    FRAMEWORK.Init(1280, 720, "FrameWork");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}