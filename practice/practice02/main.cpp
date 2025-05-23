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
        std::cout << "Initializing account with $100.00..." << std::endl;
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

void writeBalanceToFile(double balance) {
    std::ofstream file(BALANCE_FILE);
    if (!file) {
        std::cerr << "Error: Could not open file to write balance.\n";
        exit(1);
    }
    file << std::fixed << std::setprecision(2) << balance;
    file.close();
}

void checkBalance(double balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
}

double deposit(double balance) {
    double amount;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;

    if (std::cin.fail() || amount <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Error: Deposit amount must be positive.\n";
        return balance;
    }

    balance += amount;
    writeBalanceToFile(balance);
    std::cout << "Deposit successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
    return balance;
}

double withdraw(double balance) {
    double amount;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;

    if (std::cin.fail() || amount <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Error: Withdrawal amount must be positive.\n";
        return balance;
    }

    if (amount > balance) {
        std::cout << "Error: Insufficient funds. Your balance is $" << std::fixed << std::setprecision(2) << balance << ".\n";
        return balance;
    }

    balance -= amount;
    writeBalanceToFile(balance);
    std::cout << "Withdrawal successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
    return balance;
}

int main(){   
    std::cout << "Welcome to Your Bank Account!" << std::endl;
    double balance = readBalanceFromFile();

    int userChoice;
    while (true) {
        std::cout << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Deposit Money" << std::endl;
        std::cout << "3. Withdraw Money" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << std::endl;

        std::cout << "Enter Your Choice: ";
        std::cin >> userChoice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
            std::cout << "Invalid Output!(Please enter a number 1-4)." << std::endl;
            continue;
        }
        if (userChoice == 1) {
            checkBalance(balance);
        }
        else if (userChoice == 2) {
            balance = deposit(balance);
        }
        else if (userChoice == 3) {
            balance = withdraw(balance);
        }
        else if (userChoice == 4) {
            std::cout << "Thank you for using the bank account program. Goodbye!\n";
            break;
        }
        else {
            std::cout << "Invalid Output!(Please enter a number 1-4)." << std::endl;
            continue;
        }
    }

    return 0;
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
