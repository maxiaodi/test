#pragma once
#include "Command.h"
class MoveCommand :
    public Command
{
private:
    int forwardOrBackward;
public:
    MoveCommand(int FOrB) :forwardOrBackward(FOrB){}
    void execute(Location& loc);
};

