#include <iostream>
#include <vector>
#include <string>


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
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        //Decides what to do based on user input
        if (choice == 1) {
            std::cout << "Added num to vector!!" << std::endl;
            }
        else if (choice == 2) {
            std::cout << "Printed vector!!" << std::endl;
            }
        else if (choice == 3) {
            std::cout << "Doubled the vector!!" << std::endl;
            }
        else if (choice == 4) {
            std::cout << "Found the sum!!" << std::endl;
            }
        else if (choice == 5) {
            std::cout << "The multiples are..." << std::endl;
            }
        else if (choice != 6) {
            std::cout << "Invalid Choice!! Please try again!" << std::endl;
            }
        }
    return 0;
    }
