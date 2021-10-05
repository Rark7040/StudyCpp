#include "Command.hpp"
using namespace std;

class TestCommand : public Command {

	public:
		bool execute();

		TestCommand(): Command("test"){

		}
};

bool TestCommand::execute(){
	cout << "TestCommamd: killed console" << endl;
	return true;
}
