#pragma once
#include<iostream>
using namespace std;
#include "Location.h"
#include "Command.h"

class Robot {
private:
	Location location;
public:
	Robot(int x = 0, int y = 0, int dir = 0) :location(x, y, dir){}
	string getLocation();
	void accept(Command* command);
};