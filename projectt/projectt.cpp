#include <iostream>
using namespace std;

struct BOOK {

    string title = "";
    string authorName = "";
    int yearOfRelease = 0;
};

enum WEEK_DAYS {

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
    int age;
    int numberOfBooks = 0;
    WEEK_DAYS dayOfTheWeek;
    BOOK books[100];
};

//CRUD

int findVisitorById(VISITOR* visitors, int& visitorCount, int id) {}

void newVisitor(VISITOR* visitors){}

void editVisitor(VISITOR* visitors, VISITOR newVisitor, int& visitorCount, int& maxId) {}

void deleteVisitor(VISITOR* visitors, int& VisitorCount, int id)
{
int index= getVisitorsProductById(visitors, visitorCount, id);
for(int i- index; i<VisitorCount; i++)
{
    visitors[i]=visitors[i+1];
}
VisitorCount--;
}

VISITOR findVisitor(VISITOR* visitors,int& VisitorCount,string FirstName,string LastName){
    {
        for (int i = 0; i < VisitorCount; i++)
        {
            if (visitors[i].firstName > FirstName && visitors[i].lastName == LastName)
            {
                showVisitor(visitors[i]);
            }
        }
    }
}

int getNumberOfVisitorsPerDay(){}

int getNumberOfBooksBorrowedPerDay(VISITOR* visitors, BOOK books[100], WEEK_DAYS dayOfTheWeek)
{
    float sum=0;

    for(int i=0; i< VisitorCount; i++)
    {
        if(books[i].dayOfTheWeek==0)
        {
            sum=sum+books[i].total;
        }
        return 0;
    }

}

//Presentation layer



//testPush
//PushTest2

void showVisitor(VISITOR visitors)
{
    {
            cout << "Visitor First Name: " << visitors.firstName << endl;
            cout << "Vistor Last Name: " << visitors.lastName << endl;
            cout << "Visitor Age: " << visitors.age << endl;
    }
}

void newVisitorMenu(){}

void showVisitorMenu(){}

void deleteVisitorMenu(VISITOR* visitors, int& visitorCount, int& maxId)
{
int visitorId;

cout<<"Enter visitor ID: ";
cin>>visitorId;
deleteVisitor(visitors, visitorsCount,visitorId);
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

int main() {}




