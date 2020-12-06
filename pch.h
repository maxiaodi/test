#pragma once

#include<map>
#include<string>
#include<string.h>
#include<regex>
#include<iostream>

#include "gtest/gtest.h"

#include"Robot.h"
#include "MoveNCommand.h"
#include "TurnLeftCommand.h"
#include "TurnRightCommand.h"
#include "TurnRoundCommand.h"
using namespace std;

const char dir[4] = { 'N','E','S','W' };
enum command {
	LEFT = 1, RIGHT, FORWARD, BACKWARD, ROUND
};
extern map<string, command> command2int;
void InitCommand2Int();
void executeSingleCommand(Robot* robot, const string& com);
void executeMultipleCommands(Robot* robot, const string& com);
bool isSingleCommand(const std::string& com);
void executeAllCommand(Robot* robot, const string& com);
void executeReaptCommand(Robot* robot, const std::string& com);
bool isReaptCommand(const string& com);
bool isMultipleCommand(const std::string& com);
void executeCommand(Robot* robot, const std::string& com, int count);
int countExecutionTimes(const std::string& str);
