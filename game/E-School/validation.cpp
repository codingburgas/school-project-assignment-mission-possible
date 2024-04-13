#include "validation.h"


const bool Validate::doesAccountExist(const string& targetUsername) {
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
const bool Validate::isPasswordCorrect(const string& targetUsername, const string& targetPassword) {
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

// Checks if a password contains at least one uppercase letter
bool Validate::containsUppercase(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

// Checks if a password contains at least one lowercase letter
bool Validate::containsLowercase(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return true;
        }
    }
    return false;
}

// Checks if a password contains at least one digit
bool Validate::containsDigit(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) {
        if (password[i] >= '0' && password[i] <= '9') {
            return true;
        }
    }
    return false;
}

// Checks if a password contains at least one special character
bool Validate::containsSpecial(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) {
        if (!(isalnum(password[i]))) {
            return true;
        }
    }
    return false;
}