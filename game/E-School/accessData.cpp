#include "accessData.h"

void DataAccess::addAccount(const string& email, const string& username, const string& password) const {
    ofstream file("../data/accounts.csv", ios_base::app);
    file << email << ',' << username << ',' << password << "\n";
    file.close();
}