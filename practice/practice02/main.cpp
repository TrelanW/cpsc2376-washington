// practice02.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <iomanip>

const std::string BALANCE_FILE = "account_balance.txt";

double readBalanceFromFile() {
    std::ifstream file(BALANCE_FILE);
    double balance = 0.0;

    //Try to open file for reading
    if (!file.is_open()) {
        //If file doesn't exist exist, create it with $100
        std::ofstream createfile("balance.txt");
        if (!createfile) {
            std::cerr << "Failed to load balance." << std::endl;
            std::exit(1);
        }
        balance = 100.0;
        createfile << balance;
        createfile.close();
        std::cout << "Initializing account with $100.00..." << std::endl << std::endl;
    }
    else {
        file >> balance;
        if (file.fail()) {
            std::cerr << "Error: Failed to read balance from file.\n";
            exit(1);
        }
        file.close();
        std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl << std::endl;

    }
    return balance;
}

void displayMenu() {
    std::cout << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << std::endl;
}

int main(){   
    std::cout << "Welcome to Your Bank Account!" << std::endl;
    readBalanceFromFile();
    displayMenu();

    int balance;
    int userChoice;
    std::cout << "Enter Your Choice: ";
    std::cin >> userChoice;

    if (userChoice == 1) {

    }
    else if (userChoice == 2) {

    }
    else if (userChoice == 3) {

    }
    else if (userChoice == 4) {

    }
    else {
        std::cout << "Invalid Output!" << std::endl;
        std::cout << "Would you like to display menu again? (y/n):";
        char choice;
        std::cin >> choice;
        if (choice == 'y') {
            displayMenu();
            std::cout << "Enter Your Choice: ";
            std::cin >> userChoice;
        }
        else if (choice == 'n') {
            return 1;
        }
        else {
            std::cout << "Invalid Input Again!! Your're Out!!!" << std::endl;
            return 1;
        }

    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
