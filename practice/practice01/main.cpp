#include <iostream>
#include <vector>

// Function to add a number to the vector (Pass-by-Reference)
void addNumber(std::vector<int>& numbers, int num) {
    numbers.push_back(num);
    std::cout << "Number added successfully!" << std::endl;
}

//Function to print numbers in vector
void printVector(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "No numbers stored yet." << std::endl;
        return;
    }
    else {
        for (int num : numbers) {
            std::cout << num << " ";
        }
    }

}

void doubleVector(std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "No numbers stored yet." << std::endl;
        return;
    }
    else {
        for (int& num : numbers) {
            num *= 2;
        }
        /*for (int i = 0; i < numbers.size(); ++i) {
            std::cout << numbers.at(i) * 2 << std::endl;*/
        
    }
}

int main()
{
    std::vector<int> numbers;
    int choice = 0;
    int num;

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
            int num;
            std::cout << "What number would you like to enter: ";
            std::cin >> num;
            addNumber(numbers, num);
            }
        else if (choice == 2) {
            //std::cout << "Printed vector!!" << std::endl;
            printVector(numbers);
            }
        else if (choice == 3) {
            doubleVector(numbers);
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
