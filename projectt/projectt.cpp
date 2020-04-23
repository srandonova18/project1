#include <iostream>
using namespace std;

struct BOOK {

    string title = "";
    string authorName = "";
    short int yearOfRelease = 0;
};

enum class WEEK_DAYS {

    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

struct VISITOR {

    string firstName = "";
    string lastName = "";
    short int age = 0;
    short int numberOfBooks = 0;
    int id = 0;
    WEEK_DAYS dayOfTheWeek = WEEK_DAYS::MON;
    BOOK books[7];
};

//CRUD

int findVisitorById(VISITOR* visitors, int& visitorCount, int id) {

    for (int i = 0; i < visitorCount; i++) {

        if (visitors[i].id == id) {

            return i;
        }
    }

    return -1;
}

void newVisitor(VISITOR* visitors, int& visitorCount, VISITOR newVisitor, int& maxId) {

    newVisitor.id = maxId;
    visitors[visitorCount] = newVisitor;
    visitorCount++;
    maxId++;
}

void editVisitor(VISITOR* visitors, VISITOR newVisitor, int& visitorsCount, int& maxId) {

    int index = findVisitorById(visitors, visitorsCount, maxId);
    visitors[index] = newVisitor;
}


void deleteVisitor(VISITOR* visitors, int& visitorCount, int id) {
    
    int index = findVisitorById(visitors, visitorCount, id);

    for(int i = index; i < visitorCount; i++) {

        visitors[i] = visitors[i + 1];
    }

    visitorCount--;
}

VISITOR findVisitor(VISITOR* visitors, int& visitorCount, int id) {
    
    int index = findVisitorById(visitors, visitorCount, id);
    return visitors[index];
}

int getNumberOfVisitorsPerDay(VISITOR* visitors, int visitorCount, WEEK_DAYS dayOfTheWeek){
    
    int howManyVisitors = 0;

    for (int i = 0; i < visitorCount; i++) {

        if (visitors[i].dayOfTheWeek == dayOfTheWeek) {

            howManyVisitors++;
        }
    }

    return howManyVisitors;

}

int getNumberOfBooksBorrowedPerDay(VISITOR* visitors, int visitorCount, WEEK_DAYS dayOfTheWeek) {

    int numberBooks = 0;

    for (int i = 0; i < visitorCount; i++) {

        if (visitors[i].dayOfTheWeek == dayOfTheWeek) {

            numberBooks = numberBooks + visitors[i].numberOfBooks;
        }
    }

    return numberBooks;
}


int getAverageOfVisitorsAgesForTheWeek(VISITOR* visitors, int visitorCount) {

    short int ages = 0;

    for (int i = 0; i < visitorCount; i++) {

        ages = ages + visitors[i].age;
    }

    ages = ages / visitorCount;

    return ages;
}


//PRESENTATION LAYER

void newVisitorMenu(int Choice) {
    cout << "This is a new Visitor Menu" << endl;
    cout << "Fill this to create a new Visitor" << newVisitor;






}
void showVisitorMenu(){}

void deleteVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId)
{
    int visitorId;

    cout<<"Enter visitor ID: ";
    cin>>visitorId;

    deleteVisitor(visitors, visitorCount,visitorId);
}

void showReportsMenu(){}

void editVisitorMenu(VISITOR* visitors, int& visitorCount) {}

bool showMainMenu(VISITOR* visitors, int& visitorCount, int& maxId){

    int choice;

    cout << "\nMAIN MENU" << endl;
    cout << "1. Register a new visitor" << endl;
    cout << "2. Show all visitors' profiles" << endl;
    cout << "3. Edit an existing visitor's profile" << endl;
    cout << "4. Delete an existing visitor's profile" << endl;
    cout << "5. Reports" << endl;
    cout << "6. Exit" << endl;
    cout << "Your choice is: ";

    cin >> choice;

    switch (choice) {

    case 1: {

        newVisitorMenu();
        break;
    }

    case 2: {

        showVisitorMenu();
        break;
    }

    case 3: {

        editVisitorMenu(visitors, visitorCount);
        break;
    }

    case 4: {

        deleteVisitorMenu();
        break;
    }

    case 5: {

        showReportsMenu();
        break;
    }

    case 6: {

        return false;
    }

    default: break;

    }
}

int main() {

    int visitorCount = 0;
    int maxId = 1;
    VISITOR visitors[30];

    bool doShowMenu = 1;

    do {

        doShowMenu = showMainMenu(visitors, visitorCount, maxId);
    } while (doShowMenu);

}




