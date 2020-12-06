//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
map<string, command> command2int;
void InitCommand2Int() {
	command2int["LEFT"] = LEFT;
	command2int["RIGHT"] = RIGHT;
	command2int["FORWARD"] = FORWARD;
	command2int["BACKWARD"] = BACKWARD;
	command2int["ROUND"] = ROUND;
}

void executeAllCommand(Robot* robot, const string& com) {
	if (isReaptCommand(com)) 
		executeReaptCommand(robot, com);
	else if (isMultipleCommand(com))
		executeMultipleCommands(robot, com);
	else if (isSingleCommand(com))
		executeSingleCommand(robot, com);
	else {
		cout << "ÃüÁî´íÎó" << endl;
	}
	return;
}

void executeReaptCommand(Robot* robot, const std::string& com){
	smatch reg_res;
	regex pattern("\^REAPT\\(((LEFT|RIGHT|FORWARD|BACKWARD|ROUND)(\\(([1-9])\\))?),([1-9]|10)\\)\$");
	regex_match(com, reg_res, pattern);
	int commandCount = stoi(reg_res[5]);
	while (commandCount--)
		executeCommand(robot, reg_res[2], countExecutionTimes(reg_res[4]));
}

bool isReaptCommand(const string& com) {
	regex pattern("\^REAPT\\(((LEFT|RIGHT|FORWARD|BACKWARD|ROUND)(\\(([1-9])\\))?),([1-9]|10)\\)\$");
	bool flag = regex_match(com, pattern);
	return flag;
}

void executeMultipleCommands(Robot* robot, const string& com) {
	regex pattern_("(LEFT|RIGHT|FORWARD|BACKWARD|ROUND)(\\(([1-9]|10)\\))?");
	smatch reg_res;
	auto pos = com.cbegin();
	auto end = com.cend();
	for (; regex_search(pos, end, reg_res, pattern_); pos = reg_res.suffix().first)
		executeSingleCommand(robot, reg_res[0]);
}

bool isMultipleCommand(const std::string& com){
	regex patterns("\^\\[((LEFT|RIGHT|FORWARD|BACKWARD|ROUND)(\\(([1-9]|10)\\))?,)*(LEFT|RIGHT|FORWARD|BACKWARD|ROUND)(\\(([1-9]|10)\\))?\\]\$");
	return regex_match(com, patterns);
}

void executeSingleCommand(Robot* robot, const string& com) {
	regex pattern("\^(LEFT|RIGHT|FORWARD|BACKWARD|ROUND)(\\(([1-9]|10)\\))?\$");
	smatch reg_res;
	regex_match(com, reg_res, pattern);

	int count = 1;
	if (reg_res[3] != "")
		count = stoi(reg_res[3]);
	executeCommand(robot, reg_res[1], countExecutionTimes(reg_res[3]));
}

bool isSingleCommand(const std::string& com) {
	regex pattern("\^(LEFT|RIGHT|FORWARD|BACKWARD|ROUND)(\\(([1-9])\\))?\$");
	return regex_match(com, pattern);
}

int countExecutionTimes(const std::string& str) {
	int count = 1;
	if (str != "")
		count = stoi(str);
	return count;
}

void executeCommand(Robot* robot, const std::string& com, int count) {
	Command* command = nullptr;
	while (count--) {
		switch (command2int[com]) {
		case LEFT:
			command = new TurnLeftCommand();
			break;
		case RIGHT:
			command = new TurnRightCommand();
			break;
		case FORWARD:
			command = new MoveCommand(1);
			break;
		case BACKWARD:
			command = new MoveCommand(-1);
			break;
		case ROUND:
			command = new TurnRoundCommand();
			break;
		default:
			command = new Command();
			break;
		}
		robot->accept(command);
		delete command;
	}
}
