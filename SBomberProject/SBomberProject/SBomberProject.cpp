
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include "ScreenSingleton.h"

#include <stdlib.h>
#include <time.h>

using namespace std;

//========================================================================================================================

int main(void)
{

    srand((unsigned)time(NULL));
    MyTools::OpenLogFile("log.txt");

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

    MyTools::CloseLogFile();

    return 0;
}
