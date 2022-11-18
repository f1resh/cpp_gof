#include <iostream>

#include "LevelGUI.h"
#include "ScreenSingleton.h"

#define MESSAGE_LIVE_TIME 3000

using namespace std;

void LevelGUI::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_White);

    ScreenSingleton::getInstance().GotoXY(x, y);
    char* buf = new (nothrow) char[width + 1];
    if (buf == nullptr)
    {
        return;
    }
    memset(buf, '+', width);
    buf[width] = '\0';
    cout << buf;
    ScreenSingleton::getInstance().GotoXY(x, y + height);
    cout << buf;
    delete [] buf;
    buf = nullptr;
    
    for (size_t i = size_t(y); i < height + y; i++)
    {
        ScreenSingleton::getInstance().GotoXY(x, (double)i);
        cout << "+";
        ScreenSingleton::getInstance().GotoXY(x + width - 1, (double)i);
        cout << "+";
    }

    ScreenSingleton::getInstance().GotoXY(3, 1);
    cout << "FramePerSecond: " << static_cast<int>(fps / (passedTime / 1000.0));
    ScreenSingleton::getInstance().GotoXY(25, 1);
    cout << "PassedTime: " << static_cast<int>(passedTime / 1000.0) << " sec";
    ScreenSingleton::getInstance().GotoXY(46, 1);
    cout << "BombsNum: " << bombsNumber;
    ScreenSingleton::getInstance().GotoXY(62, 1);
    cout << "Score: " << score;

    if (!messageQueue.empty()) {
        ScreenSingleton::getInstance().GotoXY(4, 22);
        cout << "Tank: " << messageQueue.front();
    }
}

void LevelGUI::PushMessageToQueue(std::string message)
{
    messageQueue.push(message);
}

void LevelGUI::ClearMessageQueue()
{
    //std::queue<std::string>().swap(messageQueue);
    messageQueue = std::queue<std::string>();
}

void __fastcall LevelGUI::SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;

    //Remove message from queue every 3 seconds
    if (!messageQueue.empty() && passedTime  / MESSAGE_LIVE_TIME > messageCounter) {
        messageQueue.pop();
        messageCounter = (int)(passedTime  / MESSAGE_LIVE_TIME);
    }
}
