#include "SBomberImpl.h"

#include <windows.h>
#include <conio.h>

using namespace std;

SBomber::SBomber()
    : pimpl (new SBomberImpl)
{
    
}

SBomber::~SBomber()
{

    delete pimpl;
}

bool SBomber::GetExitFlag() const
{
     return pimpl->exitFlag;
}

void SBomber::MoveObjects()
{
    pimpl->MoveObjects();
};

void SBomber::CheckObjects()
{
    fileLogger.Write(string(__FUNCTION__) + " was invoked");

    pimpl->CheckPlaneAndLevelGUI();
    pimpl->CheckBombsAndGround();
};


void SBomber::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    fileLogger.Write(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        pimpl->exitFlag = true;
        break;

    case 72: // up
        pimpl->FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        pimpl->FindPlane()->ChangePlaneY(0.25);
        break;

    case 'b':
        pimpl->DropBomb();
        break;

    case 'B':
        pimpl->DropBomb();
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    pimpl->DrawFrame();
}

void SBomber::TimeStart()
{
    pimpl->TimeStart();
}

void SBomber::TimeFinish()
{
    pimpl->TimeFinish();
}

