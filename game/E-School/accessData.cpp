#include "accessData.h"

char currentUser[25] = "";

void DataAccess::addAccount(const string& username, const string& password)const {
    ofstream file("../data/accounts.csv", ios_base::app);
    file << username << ',' << password << "\n";
    file.close();
}

void DataAccess::addAccountInGradeBook(const string& username, const string& password)const {
    ofstream file("../data/gradeBook.csv", ios_base::app);
    file << username << ',' << password;
    file.close();
}
void DataAccess::addGrade(const string& subject, const string& grade)const {
    ofstream file("../data/gradeBook.csv", ios_base::app);
    file << currentUser <<',' << subject << ',' << grade << "\n";
    file.close();
}
