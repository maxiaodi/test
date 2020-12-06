#include "pch.h"
#include "TurnRightCommand.h"

void TurnRightCommand::execute(Location& loc) {
	loc.turnRight();
}