// HandleCommand.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "HandleCommand.h"
#include "Console.hpp"
using namespace std;

int main()
{
	Console * console = new Console;
	console->start();
	return 0;
}