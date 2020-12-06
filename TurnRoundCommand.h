#pragma once
#include "Command.h"
class TurnRoundCommand :
    public Command
{
public:
    void execute(Location& loc);
};

