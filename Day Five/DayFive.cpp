#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

const string INPUTTESTFILE = "day5TestInput.dat";
const string INPUTFILE = "day5Input.dat";

// PART ONE
int answerPartOne(string iFile) {
    ifstream stream(iFile);
    vector<int> offsets;
    int extractedInt;

    while (stream >> extractedInt) {
        offsets.push_back(extractedInt);
    }

    int nbSteps = 0;
    int currentLocation = 0;
    while (currentLocation >= 0 && currentLocation < offsets.size()) {
        int nextLocation = currentLocation + offsets[currentLocation];
        offsets[currentLocation]++;
        currentLocation = nextLocation;
        nbSteps++;
    }

    return nbSteps;
}

// PART TWO
int answerPartTwo(string iFile) {
    ifstream stream(iFile);
    vector<int> offsets;
    int extractedInt;

    while (stream >> extractedInt) {
        offsets.push_back(extractedInt);
    }

    int nbSteps = 0;
    int currentLocation = 0;
    while (currentLocation >= 0 && currentLocation < offsets.size()) {
        int nextLocation = currentLocation + offsets[currentLocation];

        if (offsets[currentLocation] >= 3) {
            offsets[currentLocation]--;
        } else {
            offsets[currentLocation]++;
        }

        currentLocation = nextLocation;
        nbSteps++;
    }

    return nbSteps;
}

// MAIN
int main() {
    assert(answerPartOne(INPUTTESTFILE) == 5);
    cout << "Answer for Part One : " << answerPartOne(INPUTFILE) << endl;

    assert(answerPartTwo(INPUTTESTFILE) == 10);
    cout << "Answer for Part Two : " << answerPartTwo(INPUTFILE) << endl;
}
