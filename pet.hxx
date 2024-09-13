#ifndef PET_H
#define PET_H

#include <string>

class Pet {
public:
    Pet();
    void showStatus();
    void feed();
    void play();
    void rest();
    void timePasses();

private:
    int hunger;
    int happiness;
    int energy;
    std::string activityState;
    std::string moodState;

    void decreaseEnergy();
    void updateActivityState();
    void updateMoodState();
};

#endif // PET_H
