#pragma once
class Location{
private:
	int x;
	int y;
	int direction;
public:
	Location(int x = 0, int y = 0, int dir = 0) :x(x), y(y), direction(dir) {
	}
	string getLocation();
	void turnLeft();
	void turnRight();
	void move(int forwardOrBackward);
	void turnRound();
};

