#pragma once
#include <string>
using namespace std;

//structure with information about the books
struct BOOK {

	string title = "";
	string authorName = "";
	short int yearOfRelease = 0;
};

//declaring the enum with the days of the week
enum class WEEK_DAYS {

	UNKNOWN,
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
};

//structure with information about the visitors
struct VISITOR {

	string firstName = "";
	string lastName = "";
	short int age = 0;
	WEEK_DAYS dayOfTheWeek = WEEK_DAYS::UNKNOWN;
	short int numberOfBooks = 0;
	BOOK books[7];
	int id = 0;
};
