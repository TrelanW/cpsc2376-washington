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
    }
}

void findMultiple(const std::vector<int>& numbers) {
    int multiple;
    std::cout << "For what number would like to find multiples of: ";
    std::cin >> multiple;

    if (multiple == 0) {
        std::cout << "Cannot check for multiples of zero!" << std::endl;
        return;
    }
    else {
        bool found = false;
        for (int num : numbers) {
            if (num % multiple == 0) {
                std::cout << num << " ";
                found = true;
            }
            else if (!found) {
                std::cout << "None found." << std::endl;
            }
        }
    }
}

// Function to calculate sum
int getSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

int main()
{
    std::vector<int> numbers;
    int choice = 0;

    //Displays the menu and asks for the user input
    while (choice != 6) {
        std::cout << "\n Vector Menu" << std::endl;
        std::cout << "1. Add number to vector" << std::endl;
        std::cout << "2. Print vector" << std::endl;
        std::cout << "3. Double the vector" << std::endl;
        std::cout << "4. Find the sum" << std::endl;
        std::cout << "5. Find Multiples" << std::endl;
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
            std::cout << "Sum: " << getSum(numbers) << std::endl;
            }
        else if (choice == 5) {
            findMultiple(numbers);
            }
        else if (choice != 6) {
            std::cout << "Invalid Choice!! Please try again!" << std::endl;
            }
        }
    return 0;
    }
