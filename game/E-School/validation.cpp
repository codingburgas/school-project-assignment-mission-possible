#include "validation.h"

// Check if an account with the given username exists in the accounts file.
const bool Validate::doesAccountExist(const string& targetUsername) {
    ifstream file("../data/accounts.csv"); // Open the accounts file
    string line;
    string storedUsername;
    while (getline(file, line)) { // Read each line in the file
        istringstream iss(line);
        if (getline(iss, storedUsername, ',')) { // Extract the stored username from the line
            if (storedUsername == targetUsername) { // Compare stored username with target username
                cout << storedUsername; // Output the stored username (for debugging)
                return true; // Return true if the target username matches any stored username
            }
        }
    }
    return false; // Return false if the target username is not found
}

// Check if the given password matches the password associated with the given username.
const bool Validate::isPasswordCorrect(const string& targetUsername, const string& targetPassword) {
    ifstream file("../data/accounts.csv"); // Open the accounts file
    string line;

    while (getline(file, line)) { // Read each line in the file
        istringstream iss(line);
        string storedUsername, storedPassword;

        if (getline(iss, storedUsername, ',') && getline(iss, storedPassword, ',')) {
            if (storedUsername == targetUsername && storedPassword == targetPassword) {
                return true; // Return true if the target username and password match any stored pair
            }
        }
    }
    return false; // Return false if the target username and password are not found
}

// Check if the password contains at least one uppercase letter.
bool Validate::containsUppercase(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) { // Loop through each character in the password
        if (password[i] >= 'A' && password[i] <= 'Z') { // Check if the character is an uppercase letter
            return true; // Return true if an uppercase letter is found
        }
    }
    return false; // Return false if no uppercase letter is found
}

// Check if the password contains at least one lowercase letter.
bool Validate::containsLowercase(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) { // Loop through each character in the password
        if (password[i] >= 'a' && password[i] <= 'z') { // Check if the character is a lowercase letter
            return true; // Return true if a lowercase letter is found
        }
    }
    return false; // Return false if no lowercase letter is found
}

// Check if the password contains at least one digit.
bool Validate::containsDigit(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) { // Loop through each character in the password
        if (password[i] >= '0' && password[i] <= '9') { // Check if the character is a digit
            return true; // Return true if a digit is found
        }
    }
    return false; // Return false if no digit is found
}

// Check if the password contains at least one special character.
bool Validate::containsSpecial(const string& password) {
    for (size_t i = 0; i < password.length(); ++i) { // Loop through each character in the password
        if (!(isalnum(password[i]))) { // Check if the character is not alphanumeric
            return true; // Return true if a special character is found
        }
    }
    return false; // Return false if no special character is found
}
