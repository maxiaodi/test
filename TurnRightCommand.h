#pragma once
#include "Command.h"
class TurnRightCommand :
    public Command
{
public:
    void execute(Location& loc);
};

