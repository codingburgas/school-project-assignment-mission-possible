#pragma once

#include "pch.h"


class Validate {
public:
    const bool doesAccountExist(const string& targetUsername);
    const bool isPasswordCorrect(const string& targetUsername, const string& targetPassword);
    bool containsSpecial(const string& password);
    bool containsDigit(const string& password);
    bool containsLowercase(const string& password);
    bool containsUppercase(const string& password);
};
