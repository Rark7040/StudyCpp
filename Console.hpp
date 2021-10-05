#include <string>
#include <iostream>
#include "Command.hpp"
#include "TestCommand.hpp"
using namespace std;

class Console {

	protected:
		Command *command_list[1];
		int getCommand(string maybe_command);
		bool onRun();

	public:
		void start();
		void end();

	Console(){
		TestCommand *test_cmd = new TestCommand();
		this->command_list[0] = test_cmd;
	}
};

int Console::getCommand(string maybe_command) {
	int i = 0;

	for (Command *command : this->command_list) {
		if (command->getCommand() == maybe_command) return i;
		++i;
	}
	return -1;
}

void Console::start() {
	cout << "start console" << endl;
	for(;;){
		if (this->onRun()) {
			this->end();
			return;
		}
	}
}

//true = kill
bool Console::onRun() {
	string input;
	int responce;
	std::getline(cin, input);
	responce = this->getCommand(input);

	if(responce == -1 || sizeof(this->command_list) / sizeof(this->command_list[0]) < responce){
		cout << input + " is not valid command" << endl;
		return false;
	}

	return this->command_list[responce]->execute();
}

void Console::end() {
	string no_use;
	cout << "end console" << endl;
	std::getline(cin, no_use);
}