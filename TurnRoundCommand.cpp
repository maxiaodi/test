#include "pch.h"
#include "TurnRoundCommand.h"

void TurnRoundCommand::execute(Location& loc) {
	loc.turnRound();
}