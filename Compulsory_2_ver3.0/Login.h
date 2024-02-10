#pragma once

#include <iostream>

class Login {
private:
    const std::string userName = "Meisam";
    const std::string password = "theChosenOne";

    std::string userName_input{};
    std::string userPassword_input{};

    int loginCounter{};
    int passwordLoginCounter{};

    bool userNameCorrect = true;
    bool passwordCorrect = false;
    bool bIsThrough = false;

public:
    void mainframe();
    void loginMainFrame();
    bool GetIsThrough() { return bIsThrough; }
};

