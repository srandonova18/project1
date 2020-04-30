#pragma once
#include <string>
#include "StructuresAndEnum.h"
using namespace std;

void newVisitorMenu(VISITOR*, int&, int&);

void showVisitorsMenu(VISITOR*, int&, int&);

void editVisitorMenu(VISITOR*, int&);

void showAllBorrowedBooksMenu(VISITOR*, int&);

void deleteVisitorMenu(VISITOR*, int&, int&);

void showBorrowedBooksByADetailMenu(VISITOR*, int&);

void showReportsMenu(VISITOR*, int&, int&);

bool showMainMenu(VISITOR*, int&, int&);
