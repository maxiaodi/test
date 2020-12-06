#include "pch.h"
#include "Robot.h"

string Robot::getLocation() {
	return location.getLocation();
}

void Robot::accept(Command* command) {
	command->execute(location);
}
