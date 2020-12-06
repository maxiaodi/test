#include "pch.h"
#include "MoveNCommand.h"
void MoveCommand::execute(Location& loc) {
    loc.move(forwardOrBackward);
}