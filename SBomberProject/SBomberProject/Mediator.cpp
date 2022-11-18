#include "Mediator.h"
#include "Tank.h"

void Mediator::Notify(const GameObject* sender, const std::string message)
{
	auto pTank = dynamic_cast<const Tank*>(sender);
	if (pTank!=nullptr) {
		if (message == "I'm dead x_x") {
			pLevelGUI->ClearMessageQueue();
		}
		pLevelGUI->PushMessageToQueue(message);
	}
}
