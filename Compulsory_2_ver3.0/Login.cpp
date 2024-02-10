#include "Login.h"
#include <iostream>
#include <string>
#include <cstdlib>

void Login::mainframe() {
    while (userNameCorrect) {
        std::cout << "You have " << 3 - loginCounter << " attempts";
        std::cout << "Please enter username: ";
        std::getline(std::cin, userName_input);

        if (userName_input == userName) {
            std::cout << "Correct";
            userNameCorrect = false;
        }
        else {
            ++loginCounter;
        }

        if (loginCounter == 3) {
            std::cout << "Too many tries young one";
            exit(0);
        }
    }
    loginMainFrame();
}

void Login::loginMainFrame() {
    system("cls");

    passwordCorrect = true;

    while (passwordCorrect) {
        std::cout << "You have " << 3 - passwordLoginCounter << " attempts" << std::endl;
        std::cout << "Please enter password: ";
        std::getline(std::cin, userPassword_input);

        if (userPassword_input == password) {
            std::cout << "Correct";
            bIsThrough = true;
            passwordCorrect = false;
        }
        else {
            ++passwordLoginCounter;
        }

        if (passwordLoginCounter == 3) {
            std::cout << "Too many tries young one";
            exit(0);
        }
    }
    // IF PASSWORD IS CORRECT YOU GET TIME FOR GAMING :)))
    // gaming(cards);
}