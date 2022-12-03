
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#include "SBomber.h"
#include "MyTools.h"
#include "ScreenSingleton.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    std::srand(time(NULL));
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
    game.AnimateScrolling();
    MyTools::CloseLogFile();

    return 0;
}
