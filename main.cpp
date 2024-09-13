#include <iostream>
#include <string>
#include <iomanip>          // For formatting time
#include <limits>           // For numeric_limits
#include "pet.hxx"
#include "lib/clock.hxx"    // Updated include path

using namespace std;

// Function to get valid integer input
int getValidChoice() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
    return value;
}

void showMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Feed\n";
    cout << "2. Play\n";
    cout << "3. Rest\n";
    cout << "4. Show Status\n";
    cout << "5. Set Time\n";
    cout << "6. Advance Time (1 minute)\n";
    cout << "7. Quit\n";
    cout << "----------------\n";
    cout << "Choose an action: ";
}

int main() {
    Pet myPet;
    Clock myClock;
    int choice;
    int hour, minute;

    while (true) {
        myClock.showTime();
        showMenu();
        choice = getValidChoice(); // Use the function to get a valid choice

        switch (choice) {
            case 1:
                myPet.feed();
                break;
            case 2:
                myPet.play();
                break;
            case 3:
                myPet.rest();
                break;
            case 4:
                myPet.showStatus();
                break;
            case 5:
                cout << "Set current time (type hour (enter/return) then minute): ";
                while (!(cin >> hour >> minute)) {
                    cout << "Invalid input. Please enter numeric values for hour and minute: ";
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                }
                myClock.setTime(hour, minute);
                break;
            case 6:
                myClock.advanceTime();
                myPet.timePasses(); // Each minute affects the pet
                break;
            case 7:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }

        myPet.showStatus();
    }

    return 0;
}
