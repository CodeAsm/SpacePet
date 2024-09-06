#include <iostream>
#include <string>

using namespace std;

class Pet {
public:
    int hunger;
    int happiness;
    int energy;
    
    Pet() : hunger(50), happiness(50), energy(50) {}

    void showStatus() {
        cout << "\n--- Pet Status ---\n";
        cout << "Hunger: " << hunger << "/100\n";
        cout << "Happiness: " << happiness << "/100\n";
        cout << "Energy: " << energy << "/100\n";
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
    }

    void rest() {
        if (energy < 90) {
            energy += 10;
            cout << "Your pet took a rest. Energy +10\n";
        } else {
            energy = 100;
            cout << "Your pet is fully rested!\n";
        }
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
};

void showMenu() {
    cout << "\n--- Menu ---\n";
    cout << "1. Feed\n";
    cout << "2. Play\n";
    cout << "3. Rest\n";
    cout << "4. Show Status\n";
    cout << "5. Quit\n";
    cout << "----------------\n";
    cout << "Choose an action: ";
}

int main() {
    Pet myPet;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

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
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }

        myPet.showStatus();
    }

    return 0;
}
