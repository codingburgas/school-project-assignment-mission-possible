#include "accessData.h"

char currentUser[25] = "";

void DataAccess::addAccount(const string& username, const string& password)const {
    // Open accounts.csv file
    ofstream file("../data/accounts.csv", ios_base::app);
    // Write username and password
    file << username << ',' << password << "\n";
    // Close the file
    file.close();
}

void DataAccess::addGrade(const string& subject, const string& grade) const {
    // Open the gradeBook.csv file
    ofstream file("../data/gradeBook.csv", ios_base::app);
    // Write current user, subject and grade
    file << currentUser << ',' << subject << ',' << grade << "\n";
    // Close the file
    file.close();
}