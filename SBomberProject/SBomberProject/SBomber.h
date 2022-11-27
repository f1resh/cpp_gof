#pragma once
#include "FileLogger.h"

class SBomberImpl;

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    bool GetExitFlag() const;

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    SBomberImpl* pimpl;
};