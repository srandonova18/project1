#pragma once
#include <string>
#include "StructuresAndEnum.h"

WEEK_DAYS chooseDayOfTheWeek();

string weekDayToString(WEEK_DAYS);

void editBooksDetailsMenu(VISITOR*, int&);

void editVisitorDetailsMenu(VISITOR*, int&);

void getBorrowedBooksByTitleMenu(VISITOR*, int&);

void getBorrowedBooksByAuthorMenu(VISITOR*, int&);

void getBorrowedBooksByYearOfReleaseMenu(VISITOR*, int&);

void numberOfVisitorsPerDayReportsMenu(VISITOR*, int&);

void numberOfBooksPerDayReportsMenu(VISITOR*, int&);