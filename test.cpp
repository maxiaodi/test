#include "pch.h"
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING 1


#include "Robot.h"
#include "gtest/gtest.h"
#include "RobotTest.h"

#include<iostream>
using namespace std;


TEST_F(RobotTest, Demo1) {
	executeAllCommand(&robot, "11");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)");
	executeAllCommand(&robot, "[RIGHT,FORWARD(3),RIGHT,BACKWARD");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)");
	executeAllCommand(&robot, "[RIGHT,FORWARD(3,RIGHT,BACKWARD]");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)") << "";
	executeAllCommand(&robot, "[RIGHT,FORWARD3),RIGHT,BACKWARD]");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)") << "";
	executeAllCommand(&robot, "1231323[RIGHT,FORWARD(3),RIGHT,BACKWARD]");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)") << "";
	executeAllCommand(&robot, "[RIGHT,FORWARD(3),RIGHT,BACKWARD]1231323");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)") << "";
	executeAllCommand(&robot, "[RIGHT,FORWARD(3), RIGHT, BACKWARD]1231323");//╪сак©у╦Я
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)") << "";

	executeAllCommand(&robot, "LEFT");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,W)") << "LEFT";
	executeAllCommand(&robot, "RIGHT");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)") << "RIGHT";
	executeAllCommand(&robot, "FORWARD");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,1,N)") << "FORWARD";
	executeAllCommand(&robot, "BACKWARD");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,N)") << "BACKWARD";
	executeAllCommand(&robot, "ROUND");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,S)") << "ROUND";
}
TEST_F(RobotTest, Demo2){
	executeAllCommand(&robot, "FORWARD(3)");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,3,N)") << "FORWARD";
}
TEST_F(RobotTest, Demo3) {
	executeAllCommand(&robot, "[RIGHT,FORWARD(3),RIGHT,BACKWARD]");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(3,1,S)") << "[LEFT,FORWARD,RIGHT,BACKWARD,ROUND,FORWARD(2)]";
}
TEST_F(RobotTest, Demo4) {
	executeAllCommand(&robot, "[LEFT]");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,0,W)") << "[LEFT]";
}
TEST_F(RobotTest, Demo5) {
	executeAllCommand(&robot, "[FORWARD(2)]");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,2,N)") << "[FORWARD(2)]";
}
TEST_F(RobotTest, Demo6) {
	executeAllCommand(&robot, "REAPT(FORWARD(2),2)");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,4,N)") << "REAPT(FORWARD(2),2)";
	executeAllCommand(&robot, "REAPT(RIGHT,3)");
	EXPECT_STREQ((robot.getLocation()).c_str(), "(0,4,W)") << "REAPT(LEFT,2)";
}


int main(int argc, char** argv) {
	InitCommand2Int();

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	/*
	Robot robot;
	string str = "1";
	while (true) {
		cin >> str;
		if (str == "")
			break;
		executeAllCommand(&robot, str);
		cout << robot.getLocation() << endl;
	}
	return 0;
	*/
}