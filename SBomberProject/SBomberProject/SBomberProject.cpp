#pragma once
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#include "SBomber.h"
#include "ScreenSingleton.h"
#include "FileLoggerSingleton.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    std::srand(time(NULL));

    FileLoggerSingleton::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        ScreenSingleton::getInstance().ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    FileLoggerSingleton::getInstance().CloseLogFile();

    return 0;
}
