
#include <iostream>
#include <cstdlib>
#include <ctime>

// Algorithm listed in README.md

class Horse {
public:
    Horse();                                   // constructor
    void init(int index, int trackLength);      // initialize position of Horse
    void advance();                              // move position of horse, 50/50 chance
    void printLane();                            // print this horse's lane
    bool isWinner();                             // check if the horse has won
private:
    int position;                                // current position of horse
    int index;                                   // which horse this is 
    int trackLength;                             // length of the track
};

// Horse::Horse()
Horse::Horse() {
    position = 0;
    index = 0;
    trackLength = 15;
}

// void Horse::init(int index, int trackLength)
void Horse::init(int idx, int length) {
    index = idx;
    trackLength = length;
    position = 0;
}

// void Horse::advance()  -- 50/50 chance to move forward
void Horse::advance() {
    int coin = rand() % 2;   // random 0 or 1
    position += coin;        // increase position by 1 if coin is 1, otherwise stay the same
}

// void Horse::printLane()
void Horse::printLane() {
    for (int pos = 0; pos < trackLength; pos++) {
        if (position == pos) {
            std::cout << index; // print the horse if it is at this position
        } else {
            std::cout << '.'; // otherwise print a dot to represent the track
        }
    }
    std::cout << std::endl;
}

// bool Horse::isWinner()
bool Horse::isWinner() {
    bool winner = false;
    if (position >= trackLength) {
        winner = true; // the horse has crossed the finish line
        std::cout << "Horse " << index << " has won!" << std::endl;
    }
    return winner;
}

class Race {
public:
    Race();       // constructor: builds and initializes all horses
    void start();  // runs the race loop

private:
    static const int TRACK_LENGTH = 15;
    static const int NUM_HORSES = 5;

    Horse horses[NUM_HORSES];
};

// Race::Race()
Race::Race() {
    // Create array of horses
    // then initialize each one with its index and the track length.
    for (int i = 0; i < NUM_HORSES; i++) {
        horses[i].init(i, TRACK_LENGTH);
    }
}

// Race::start()
void Race::start() {
    int turns = 0;
    srand(time(NULL));  // seed random

    bool keepGoing = true;

    while (keepGoing) {
        turns++;
                std::cout << "\n PRESS ENTER TO CONTINUE. " << std::endl; // prompt user input to continue
                std::cin.get();

        for (int i = 0; i < NUM_HORSES; i++) {
            horses[i].advance();
            horses[i].printLane();

            if (horses[i].isWinner()) {
                keepGoing = false;
            }
        }
        std::cout << "\n---------------------------------" << std::endl;
        std::cout << "Turns taken: " << turns << std::endl; // count of turns taken
        std::cout << std::endl;  // blank line between rounds
    }
}

int main() {
    Race race;
    race.start();
    return 0;
}
