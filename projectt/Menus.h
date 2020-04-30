#pragma once
#include <string>
#include "StructuresAndEnum.h"
using namespace std;

WEEK_DAYS chooseDayOfTheWeek();

string weekDayToString(WEEK_DAYS);

void newVisitorMenu(VISITOR*, int&, int&);

void showVisitorsMenu(VISITOR*, int&, int&);

void editVisitorDetailsMenu(VISITOR*, int&);

void showAllBorrowedBooksMenu(VISITOR*, int&);

void editBooksDetailsMenu(VISITOR*, int&);

void editVisitorMenu(VISITOR*, int&);

void deleteVisitorMenu(VISITOR*, int&, int&);

void numberOfVisitorsPerDayReportsMenu(VISITOR*, int&);

void numberOfBooksPerDayReportsMenu(VISITOR*, int&);

void getBorrowedBooksByTitleMenu(VISITOR*, int&);

void getBorrowedBooksByAuthorMenu(VISITOR*, int&);

void getBorrowedBooksByYearOfReleaseMenu(VISITOR*, int&);

void showBorrowedBooksByADetailMenu(VISITOR*, int&);

void showReportsMenu(VISITOR*, int&, int&);

bool showMainMenu(VISITOR*, int&, int&);
