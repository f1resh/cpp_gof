#pragma once

#include <stdint.h>
#include "AbstractLevelGUI.h"


class LevelGUI1 : public AbstractLevelGUI {
public:
	virtual void Draw() const override;
};

class LevelGUI2 : public AbstractLevelGUI {
public:
	virtual void Draw() const override;
};



