#include "validation.h"

// Stores a password input and it outputs "*" on the screen, in order to hide it.
const bool Validate::doesAccountExist(const string& targetUsername)  {
    ifstream file("../data/accounts.csv");
    string line;
    string storedUsername;
    while (getline(file, line)) {
        istringstream iss(line);
        if (getline(iss, storedUsername, ',')) {
            if (storedUsername == targetUsername) {
                cout << storedUsername;
                return true;
            }
        }
    }
    return false;
}

// Checks if an account already exists.
const bool Validate::isPasswordCorrect(const string& targetUsername, const string& targetPassword)  {
    ifstream file("../data/accounts.csv");
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string storedUsername, storedPassword;
        
        if (getline(iss, storedUsername, ',') && getline(iss, storedPassword, ',')) {
            
            if (storedUsername == targetUsername && storedPassword == targetPassword) {
                return true;
            }
        }
    }
    return false;
}
