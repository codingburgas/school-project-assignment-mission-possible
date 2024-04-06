#pragma once

#include "pch.h"


class Validate {
public:
    const bool doesAccountExist(const string& targetUsername);  // Remove const qualifier
    const bool isPasswordCorrect(const string& targetUsername, const string& targetPassword);  // Remove const qualifier
  
};
