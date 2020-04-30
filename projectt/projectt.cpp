#include <iostream>
#include <string>
#include "StructuresAndEnum.h"
#include "Data.h"
#include "Menus.h"
using namespace std;

//the idea behind the code is a library

int main() {

	int visitorCount = 0;
	int maxId = 1;
	VISITOR visitors[30];

	//function which initializes some data (data base like)
	initializingData(visitors, visitorCount, maxId);

	bool doShowMenu = 1;

	//loop for showing the main menu unless exit option is chosen
	do {

		doShowMenu = showMainMenu(visitors, visitorCount, maxId);
	} while (doShowMenu);

}