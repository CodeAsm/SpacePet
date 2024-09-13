#include "pet.hxx"
#include <iostream>
#include <iomanip> // For formatting time

using namespace std;

Pet::Pet() : hunger(50), happiness(50), energy(50), activityState("sitting"), moodState("neutral") {}

void Pet::showStatus() {
    cout << "\n--- Pet Status ---\n";
    cout << "Hunger: " << hunger << "/100\n";
    cout << "Happiness: " << happiness << "/100\n";
    cout << "Energy: " << energy << "/100\n";
    cout << "Activity: " << activityState << "\n";
    cout << "Mood: " << moodState << "\n";
    cout << "------------------\n";
}

void Pet::feed() {
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

void Pet::play() {
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

void Pet::rest() {
    if (energy < 100) {
        energy += 10;
        cout << "Your pet took a rest. Energy +10\n";
        activityState = "sleeping"; // Goes to sleeping state
    } else {
        energy = 100;
        cout << "Your pet is fully rested!\n";
        activityState = "sitting"; // Full energy means sitting state
    }
    updateMoodState();
}

void Pet::timePasses() {
    if (hunger > 0) hunger -= 1;
    if (happiness > 0) happiness -= 1;
    if (energy > 0) energy -= 1;
    cout << "Time passes... Hunger -1, Happiness -1, Energy -1\n";
    updateMoodState(); // Update mood based on current happiness level
}

void Pet::decreaseEnergy() {
    if (energy > 10) {
        energy -= 10;
        cout << "Energy -10\n";
    } else {
        energy = 0;
        cout << "Your pet is too tired!\n";
    }
}

void Pet::updateActivityState() {
    if (energy < 20) {
        activityState = "sleeping";
    } else if (happiness < 30) {
        activityState = "sitting";
    } else {
        activityState = "playing";
    }
}

void Pet::updateMoodState() {
    if (happiness < 30) {
        moodState = "angry";
    } else if (happiness < 70) {
        moodState = "neutral";
    } else {
        moodState = "happy";
    }
}
