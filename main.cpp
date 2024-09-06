#include <iostream>
#include <string>
#include <iomanip>  // For formatting time
#include <limits>   // For numeric_limits

using namespace std;

class Pet {
public:
    int hunger;
    int happiness;
    int energy;
    string activityState; // e.g., "sleeping", "walking", "playing", "sitting"
    string moodState;     // e.g., "angry", "neutral", "happy"

    Pet() : hunger(50), happiness(50), energy(50), activityState("sitting"), moodState("neutral") {}

    void showStatus() {
        cout << "\n--- Pet Status ---\n";
        cout << "Hunger: " << hunger << "/100\n";
        cout << "Happiness: " << happiness << "/100\n";
        cout << "Energy: " << energy << "/100\n";
        cout << "Activity: " << activityState << "\n";
        cout << "Mood: " << moodState << "\n";
        cout << "------------------\n";
    }

    void feed() {
        if (hunger < 90) {
            hunger += 10;
            cout << "You fed your pet. Hunger +10\n";
        } else {
            hunger = 100;
            cout << "Your pet is full!\n";
        }
        decreaseEnergy();
        updateActivityState();
    }

    void play() {
        if (happiness < 90) {
            happiness += 10;
            cout << "You played with your pet. Happiness +10\n";
        } else {
            happiness = 100;
            cout << "Your pet is very happy!\n";
        }
        decreaseEnergy();
        updateActivityState();
    }

    void rest() {
        if (energy < 90) {
            energy += 10;
            cout << "Your pet took a rest. Energy +10\n";
        } else {
            energy = 100;
            cout << "Your pet is fully rested!\n";
        }
        updateMoodState();
    }

    // Time-based decay (per minute)
    void timePasses() {
        if (hunger > 0) hunger -= 1;
        if (happiness > 0) happiness -= 1;
        if (energy > 0) energy -= 1;
        cout << "Time passes... Hunger -1, Happiness -1, Energy -1\n";
        updateMoodState(); // Update mood based on current happiness level
    }

private:
    void decreaseEnergy() {
        if (energy > 10) {
            energy -= 10;
            cout << "Energy -10\n";
        } else {
            energy = 0;
            cout << "Your pet is too tired!\n";
        }
    }

    void updateActivityState() {
        if (energy < 20) {
            activityState = "sleeping";
        } else if (happiness < 30) {
            activityState = "sitting";
        } else {
            activityState = "playing";
        }
    }

    void updateMoodState() {
        if (happiness < 30) {
            moodState = "angry";
        } else if (happiness < 70) {
            moodState = "neutral";
        } else {
            moodState = "happy";
        }
    }
};

// Clock class to manage time
class Clock {
public:
    int hour;
    int minute;

    Clock() : hour(12), minute(0) {}

    void showTime() {
        cout << "Current time: " << setw(2) << setfill('0') << hour 
             << ":" << setw(2) << setfill('0') << minute << "\n";
    }

    void setTime(int h, int m) {
        hour = h % 24;
        minute = m % 60;
        cout << "Time set to: " << setw(2) << setfill('0') << hour 
             << ":" << setw(2) << setfill('0') << minute << "\n";
    }

    void advanceTime() {
        minute++;
        if (minute >= 60) {
            minute = 0;
            hour = (hour + 1) % 24;
        }
        showTime();
    }
};

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
