#pragma once
#include "Command.h"
class TurnLeftCommand :
    public Command
{
public:
    void execute(Location& loc);
};

