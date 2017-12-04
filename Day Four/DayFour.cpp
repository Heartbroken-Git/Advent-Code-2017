#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

const string INPUTPARTONETESTFILE = "day4Part1TestInput.dat";
const string INPUTPARTTWOTESTFILE = "day4Part2TestInput.dat";
const string INPUTFILE = "day4Input.dat";

// PART ONE
bool checkValidity(string line) {
    istringstream iss(line);
    vector<string> words;
    string extractedWord;

    while (iss >> extractedWord) {
        words.push_back(extractedWord);
    }

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (words[j] == words[i]) {
                return false;
            }
        }
    }
    return true;
}

int answerPartOne(string filename) {
    int results = 0;
    string currentLine;
    ifstream fileStream(filename, ifstream::in);

    if (fileStream.is_open()) {
        while (fileStream.good()) {
            getline(fileStream, currentLine);
            if ((currentLine != "") && checkValidity(currentLine)) {
                results++;
            }
        }
        return results;
    } else {
        return -1;
    }

}

// PART TWO
bool checkForAnagrams(string line) {
    istringstream iss(line);
    vector<string> words;
    string extractedWord;
    bool result = false;

    while (iss >> extractedWord) {
        words.push_back(extractedWord);
    }

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (words[i].length() == words[i].length()) {
                string sortedWord1 = words[i];
                sort(sortedWord1.begin(), sortedWord1.end());
                string sortedWord2 = words[j];
                sort(sortedWord2.begin(), sortedWord2.end());

                if (sortedWord1 == sortedWord2) {
                    result = true;
                }
            }
        }
        for (int j = i+1; j < words.size(); j++) {
            if (words[i].length() == words[i].length()) {
                string sortedWord1 = words[i];
                sort(sortedWord1.begin(), sortedWord1.end());
                string sortedWord2 = words[j];
                sort(sortedWord2.begin(), sortedWord2.end());

                if (sortedWord1 == sortedWord2) {
                    result = true;
                }

            }
        }
    }

    return result;

}

int answerPartTwo(string filename) {
    int results = 0;
    string currentLine;
    ifstream fileStream(filename, ifstream::in);

    if (fileStream.is_open()) {
        while (fileStream.good()) {
            getline(fileStream, currentLine);
            if ((currentLine != "") && !checkForAnagrams(currentLine)) {
                results++;
            }
        }
        return results;
    } else {
        return -1;
    }

}

// MAIN
int main() {
    assert(answerPartOne(INPUTPARTONETESTFILE) == 2);
    cout << "Answer for Part One : " << answerPartOne(INPUTFILE) << endl;

    assert(answerPartTwo(INPUTPARTTWOTESTFILE) == 3);
    cout << "Answer for Part Two : " << answerPartTwo(INPUTFILE) << endl;
}
