// practice03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector <int> nums;
    int choice = 0;

    //Displays the menu and asks for the user input
    while (choice != 6) {
        std::cout << "\n Vector Menu" << std::endl;
        std::cout << "1. Add number to vector" << std::endl;
        std::cout << "2. Print vector" << std::endl;
        std::cout << "3. Double the vector" << std::endl;
        std::cout << "4. Find the sum" << std::endl;
        std::cout << "5. Print Multiples" << std::endl;
        std::cout << "6. Exit" << std::endl;
        choice = getInt("Enter your choice: ");

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
