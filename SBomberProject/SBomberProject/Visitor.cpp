#include "Visitor.h"
#include "Bomb.h"
#include "Plane.h"
#include "MyTools.h"

#include <string>
#include <string.h>

void LogVisitor::log(const Bomb& b) const {
	std::string speed = std::to_string(b.GetSpeed());
	std::string direction = std::to_string(b.GetDirection().first) + "," + std::to_string(b.GetDirection().second);
	MyTools::WriteToLog("Bomb has speed " + speed + " with direction:["+direction+"]");
};
void LogVisitor::log(const Plane& p) const {
	std::string speed = std::to_string(p.GetSpeed());
	std::string direction = std::to_string(p.GetDirection().first) + "," + std::to_string(p.GetDirection().second);
	MyTools::WriteToLog("Bomb has speed " + speed + " with direction:[" + direction + "]");
};