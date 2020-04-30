#pragma once
#include <string>
#include "StructuresAndEnum.h"
using namespace std;

int findVisitorById(VISITOR*, int&, int);

VISITOR findVisitor(VISITOR*, int&, int);

void newVisitor(VISITOR*, int&, VISITOR, int&);

void editVisitor(VISITOR*, VISITOR, int&, int&);

int getBorrowedBooksByAuthor(VISITOR*, int, BOOK*, string);

int getBorrowedBooksByTitle(VISITOR*, int, BOOK*, string);

int getBorrowedBooksByYearOfRelease(VISITOR*, int, BOOK*, short int);

void deleteVisitor(VISITOR*, int&, int);

int getNumberOfVisitorsPerDay(VISITOR*, int, WEEK_DAYS);

int getNumberOfBooksBorrowedPerDay(VISITOR*, int, WEEK_DAYS);

int getAverageOfVisitorsAgesForTheWeek(VISITOR*, int);

int readInt(string);

void initializingData(VISITOR*, int&, int&);
