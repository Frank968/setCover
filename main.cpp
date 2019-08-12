/*
The question as bellow:
Given a list of robot names, find the list of robot names with the least 
number of characters that covers all characters int the original list.

Here is a example for using polynomial time Greedy approximate algorithm to find the solution .
1. Create universe set function
2. Chooses the most cover candidate function
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

namespace SetCover {
    // Create universe set function
    set < char > createUniverseSet(vector < string > inputVector) {
        set < char > universeSet;

        for (vector < string > ::iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
            universeSet.insert(( * it).begin(), ( * it).end());
        }
        return universeSet;
    }

    //Chooses the best candidate function
    string findMostCoverElement(set < char > & universeSet, vector < string > inputVector) {
        int mostCover = 0;
        string mostCoverName;

        for (vector < string > ::iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
            set < char > remainSet(universeSet);
            string element = * it;
            for (int i = 0; i < (int) element.length(); i++) {
                remainSet.erase(element.at(i));
            }
            int curCover = universeSet.size() - remainSet.size();

            if (curCover > mostCover || (curCover == mostCover && ( * it).length() < mostCoverName.length())) {
                mostCover = curCover;
                mostCoverName = * it;
            }
        }
        return mostCoverName;
    }

    // Solution function
    vector < string > findSolution(vector < string > inputVector) {
        // create empty output list
        vector < string > outputVector;

        // create the unique characters set
        set < char > universeSet = createUniverseSet(inputVector);

        // Loop through the input name list
        while (universeSet.size() > 0) {
            string mostCoverElement = findMostCoverElement(universeSet, inputVector);

            // Remove the used item from list
            if (!mostCoverElement.empty()) {
                // Add the found candidate to result
                outputVector.push_back(mostCoverElement);
                for (string::iterator it = mostCoverElement.begin(); it != mostCoverElement.end(); ++it) {
                    universeSet.erase( * it);
                }
            }
        }

        return outputVector;
    }

    // Display output function
    void displaySolution(vector < string > inputVector, vector < string > outputVector) {
        cout << endl << "Input: ";
        for (vector < string > ::iterator it = inputVector.begin(); it != inputVector.end(); ++it) {
            cout << * it << " ";
        }
        cout << endl << "Output: ";
        for (vector < string > ::iterator it = outputVector.begin(); it != outputVector.end(); ++it) {
            cout << * it << " ";
        }
        cout << endl;
    }

} // namespace SetCover

// main entry
int main(int argc,
    const char * argv[]) {
    // Test case 1
    string array1[] = {
        "robot1",
        "robot2",
        "robot1",
        "robot3",
        "robot3",
        "robot4",
        "abcd",
        "rbf",
        "abcdrbf"
    };
    vector < string > inputVector1(array1, array1 + sizeof(array1) / sizeof(string));
    vector < string > outputVector1 = SetCover::findSolution(inputVector1);
    SetCover::displaySolution(inputVector1, outputVector1);

    // Test case 2
    string array2[] = {
        "aba",
        "bc",
        "bcd",
        "d",
        "ae"
    };
    vector < string > inputVector2(array2, array2 + sizeof(array2) / sizeof(string));
    vector < string > outputVector2 = SetCover::findSolution(inputVector2);
    SetCover::displaySolution(inputVector2, outputVector2);

    // Test case 3
    string array3[] = {
        "aba",
        "bcf",
        "d",
        "bcd",
        "ae"
    };
    vector < string > inputVector3(array3, array3 + sizeof(array3) / sizeof(string));
    vector < string > outputVector3 = SetCover::findSolution(inputVector3);
    SetCover::displaySolution(inputVector3, outputVector3);

    return 0;
}