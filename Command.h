#pragma once
class Command
{
public:
	virtual void execute(Location& loc) {};
	virtual ~Command(){}
};

