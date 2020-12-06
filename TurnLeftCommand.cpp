#include "pch.h"
#include "TurnLeftCommand.h"

void TurnLeftCommand::execute(Location& loc) {
	loc.turnLeft();
}