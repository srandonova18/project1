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

	initializingData(visitors, visitorCount, maxId);

	bool doShowMenu = 1;

	do {

		doShowMenu = showMainMenu(visitors, visitorCount, maxId);
	} while (doShowMenu);

}