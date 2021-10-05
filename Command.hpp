#ifndef INCLUDED_COMMAND
#define INCLUDED_COMMAND
#include <string>
using namespace std;

struct Command{

	protected:
		string command;

	public:
		virtual string getCommand() final{
			return this->command;
		}
		virtual bool execute()=0;
	
		Command(string command){
			this->command = command;
		}
};
#endif