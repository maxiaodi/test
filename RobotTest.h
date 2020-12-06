#pragma once
class RobotTest :public testing::Test {
protected:
	virtual void SetUp();
	virtual void TearDown();
	Robot robot;
};

