
#include <conio.h>

#include "SBomber.h"
#include "ScreenSingleton.h"
#include "FileLoggerSingleton.h"
#include "LoggerSingleton.h"

using namespace std;

//========================================================================================================================

int main(void)
{

    LoggerSingleton::getInstance().OpenLog("log.txt");

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

    LoggerSingleton::getInstance().CloseLog();

    return 0;
}
