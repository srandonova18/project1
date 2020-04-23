#include <iostream>
#include <string>
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

VISITOR findVisitor(VISITOR* visitors, int& visitorCount, int id) {

    int index = findVisitorById(visitors, visitorCount, id);
    return visitors[index];
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

    for(int i = index; i < visitorCount-1; i++) {

        visitors[i] = visitors[i + 1];
    }

    visitorCount--;
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

    int howManyBooks = 0;

    for (int i = 0; i < visitorCount; i++) {

        if (visitors[i].dayOfTheWeek == dayOfTheWeek) {

            howManyBooks = howManyBooks + visitors[i].numberOfBooks;
        }
    }

    return howManyBooks;
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

WEEK_DAYS chooseDayOfTheWeek() {

    short int day;

    cout << endl;
    cout << "Choose the day of the visit:" << endl;
    cout << endl;
    cout << "0. Monday" << endl;
    cout << "1. Tuesday" << endl;
    cout << "2. Wednesday" << endl;
    cout << "3. Thursday" << endl;
    cout << "4. Friday" << endl;
    cout << "5. Saturday" << endl;
    cout << "6. Sunday" << endl;
    cout << endl;
    cout << "Your choice: ";

    cin >> day;

    switch (day) {

        case 0:
            return WEEK_DAYS::MON;
            break;

        case 1:
            return WEEK_DAYS::TUE;
            break;

        case 2:
            return WEEK_DAYS::WED;
            break;

        case 3:
            return WEEK_DAYS::THU;
            break;

        case 4:
            return WEEK_DAYS::FRI;
            break;

        case 5:
            return WEEK_DAYS::SAT;
            break;

        case 6:
            return WEEK_DAYS::SUN;
            break;

        default:
            break;
    }

}

string weekDayToString(WEEK_DAYS weekDay) {

    switch (weekDay) {

        case WEEK_DAYS::MON:
            return "Monday";
            break;

        case WEEK_DAYS::TUE:
            return "Tuesday";
            break;

        case WEEK_DAYS::WED:
            return "Wednesday";
            break;

        case WEEK_DAYS::THU:
            return "Thursday";
            break;

        case WEEK_DAYS::FRI:
            return "Friday";
            break;

        case WEEK_DAYS::SAT:
            return "Saturday";
            break;

        case WEEK_DAYS::SUN:
            return "Sunday";
            break;

        default:
            break;
    }

    return " ";

}

void newVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId) {
   
    VISITOR visitor;
    short int day;

    cin.ignore();

    cout << "First name: ";
    getline(cin, visitor.firstName);

    cout << "Last name: ";
    getline(cin, visitor.lastName);

    cout << "Age: ";
    cin >> visitor.age;

    visitor.dayOfTheWeek = chooseDayOfTheWeek();

    cout << endl;
    cout << "How many books did they take? : ";
    cin >> visitor.numberOfBooks;

    cout << endl;

    cout << ".::BOOKS::." << endl;

    cout << endl;

    cin.ignore();

    for (int i = 0; i < visitor.numberOfBooks; i++) {

        cout << "Title: ";
        getline(cin, visitor.books[i].title);

        cout << "Author: ";
        getline(cin, visitor.books[i].authorName);

        cout << "Year of release: ";
        cin >> visitor.books[i].yearOfRelease;

        cin.ignore();

        cout << endl;
    }

    newVisitor(visitors, visitorCount, visitor, maxId);
}

void showVisitorsMenu(VISITOR* visitors, int& visitorCount, int& maxId){

    cout << ".::All VISITORS::. " << endl;

    cout << endl;

    for (int i = 0; i < visitorCount; i++) {

        cout << i + 1 << ". " << visitors[i].firstName << " " << visitors[i].lastName << ", ";
        cout << visitors[i].age << " years old ";
        cout << "visited on " << weekDayToString(visitors[i].dayOfTheWeek) << endl;

        cout << endl;
        cout << ".::LIST OF BOOKS TAKEN::." << endl;
        cout << endl;

        for (int j = 0; j < visitors[i].numberOfBooks; j++) {

            cout << "\"" << visitors[i].books[j].title << "\" by " << visitors[i].books[j].authorName;
            cout << " released in " << visitors[i].books[j].yearOfRelease << endl;
        }

        cout << endl;
    }

}

void editVisitorMenu(VISITOR* visitors, int& visitorCount) {

    int visitorId, bookIndex;
    short int edit, bookDetail;

    cout << "Enter visitor's ID: ";
    cin >> visitorId;

    VISITOR visitor = findVisitor(visitors, visitorCount, visitorId);

    cout << "Choose what you want to edit: " << endl;
    cout << endl;
    cout << "1. First name" << endl;
    cout << "2. Last name" << endl;
    cout << "3. Age" << endl;
    cout << "4. Day of visit" << endl;
    cout << "5. Any of the books' details" << endl;
    cout << endl;
    cout << "Your choice: ";

    cin >> edit;

    cin.ignore();

    switch (edit) {

        case 1:
            cout << "First name: ";
            getline(cin, visitor.firstName);
            editVisitor(visitors, visitor, visitorCount, visitorId);
            break;

        case 2:
            cout << "Last name: ";
            getline(cin, visitor.lastName);
            editVisitor(visitors, visitor, visitorCount, visitorId);
            break;

        case 3:
            cout << "Age: ";
            cin >> visitor.age;
            editVisitor(visitors, visitor, visitorCount, visitorId);
            break;

        case 4:
            visitor.dayOfTheWeek = chooseDayOfTheWeek();
            editVisitor(visitors, visitor, visitorCount, visitorId);
            break;

        case 5:
            cout << "Choose a book: " << endl;
            cout << endl;

            for (int i = 0; i < visitor.numberOfBooks; i++) {

                cout << i + 1 << ".\" " << visitor.books[i].title << "\" by ";
                cout << visitor.books[i].authorName << " released in " << visitor.books[i].yearOfRelease << endl;
            }

            cin >> bookIndex;
            bookIndex--;

            cout << "Choose the detail you want to edit:" << endl;
            cout << endl;
            cout << "1. Title" << endl;
            cout << "2. Author" << endl;
            cout << "3. Year of release" << endl;
            cout << endl;
            cout << "Your choice: ";

            cin >> bookDetail;

            cout << endl;

            cin.ignore();

            switch (bookDetail) {

                case 1:
                    cout << "Title: ";
                    getline(cin, visitor.books[bookIndex].title);
                    editVisitor(visitors, visitor, visitorCount, visitorId);
                    break;

                case 2:
                    cout << "Author: ";
                    getline(cin, visitor.books[bookIndex].authorName);
                    editVisitor(visitors, visitor, visitorCount, visitorId);
                    break;

                case 3:
                    cout << "Year of release: ";
                    cin >> visitor.books[bookIndex].yearOfRelease;
                    editVisitor(visitors, visitor, visitorCount, visitorId);
                    break;

                default: break;
            }

        default: break;
    }


}

void deleteVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

    int visitorId;

    cout<<"Enter visitor ID: ";
    cin>>visitorId;

    deleteVisitor(visitors, visitorCount,visitorId);
}

void numberOfVisitorsPerDayReportsMenu(VISITOR* visitors, int& visitorCount) {

    WEEK_DAYS day = chooseDayOfTheWeek();
    cout << "The total number of visitors for " << weekDayToString(day) << " is: ";
    cout << getNumberOfVisitorsPerDay(visitors, visitorCount, day) << endl;
}

void numberOfBooksPerDayReportsMenu(VISITOR* visitors, int& visitorCount) {

    WEEK_DAYS day = chooseDayOfTheWeek();
    cout << "The total number of books taken for " << weekDayToString(day) << " is: ";
    cout << getNumberOfBooksBorrowedPerDay(visitors, visitorCount, day) << endl;
}

void showReportsMenu(VISITOR* visitors, int& visitorCount, int& maxId) {

    short int choice;

    cout << "Choose a report: " << endl;
    cout << endl;
    cout << "1. Get number of visitors per day" << endl;
    cout << "2. Get number of books taken per day" << endl;
    cout << "3. Get average of visitors' ages for the whole week" << endl;
    cout << endl;
    cout << "Your choice: ";

    cin >> choice;

    cout << endl;

    switch (choice) {

        case 1:
            numberOfVisitorsPerDayReportsMenu(visitors, visitorCount);
            break;

        case 2:
            numberOfBooksPerDayReportsMenu(visitors, visitorCount);
            break;

        case 3:
            cout << "The average of the visitors' ages for the week is: ";
            cout << getAverageOfVisitorsAgesForTheWeek(visitors, visitorCount) << endl;
            break;

        default: break;
    }

}

bool showMainMenu(VISITOR* visitors, int& visitorCount, int& maxId){

    int choice;

    cout << endl;
    cout << "----------------" << endl;
    cout << "   MAIN MENU" << endl;
    cout << "----------------" << endl;
    cout << endl;
    cout << "1. Register a new visitor" << endl;
    cout << "2. Show all visitors' profiles" << endl;
    cout << "3. Edit an existing visitor's profile" << endl;
    cout << "4. Delete an existing visitor's profile" << endl;
    cout << "5. Reports" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "Your choice is: ";

    cin >> choice;

    cout << endl;

    switch (choice) {

        case 1:
            newVisitorMenu(visitors, visitorCount, maxId);
            break;

        case 2:
            showVisitorsMenu(visitors, visitorCount, maxId);
            break;

        case 3:
            editVisitorMenu(visitors, visitorCount);
            break;

        case 4:
            deleteVisitorMenu(visitors, visitorCount, maxId);
            break;

        case 5:
            showReportsMenu(visitors, visitorCount, maxId);
            break;

        case 6:
            cout << "Thank you for using our program. See you soon!" << endl;
            return false;

        default: break;

    }
    return true;
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




