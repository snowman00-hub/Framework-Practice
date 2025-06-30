#include "stdafx.h"
#include "Framework.h"

int main()
{
    FRAMEWORK.init(1920, 1080, "Timber!!");
    FRAMEWORK.Do();
    FRAMEWORK.release();

    return 0;
}