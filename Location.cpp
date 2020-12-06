#include "pch.h"
#include "Location.h"

string Location::getLocation() {
	string nowLocation = "";
	nowLocation += "(";
	if (x < 0)
		nowLocation += '-';
	nowLocation += char(abs(x) + '0');
	nowLocation += ",";
	if (y < 0)
		nowLocation += '-';
	nowLocation += char(abs(y) + '0');
	nowLocation += ",";
	nowLocation += dir[direction];
	nowLocation += ")";
	//cout << nowLocation << endl;
	return nowLocation;
}
void Location::turnLeft() {
	direction = (direction + 3) % 4;
}
void Location::turnRight() {
	direction = (direction + 1) % 4;
}
void Location::move(int forwardOrBackward){
	int moveStep[][2] = {
		{0,  1},
		{1,  0},
		{0, -1},
		{-1, 0},
	};

	int i = (int)direction;
	x += forwardOrBackward * moveStep[i][0];
	y += forwardOrBackward * moveStep[i][1];
}
void Location::turnRound() {
	turnRight();
	turnRight();
}
/*
void Location::Forward(int n) {
	if (direction == 0)
		y = y + n;
	else if (direction == 1)
		x = x + n;
	else if (direction == 2)
		y = y - n;
	else if (direction == 3)
		x = x - n;
}
void Location::Backward(int n) {
	if (direction == 0)
		y = y - n;
	else if (direction == 1)
		x = x - n;
	else if (direction == 2)
		y = y + n;
	else if (direction == 3)
		x = x + n;
}
*/