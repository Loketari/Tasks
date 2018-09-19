#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> initial {4,6,8, 15};

int randomize()
{
    return rand() % (initial.size());
}

int main()
{
    vector<int> mixedValues(1);
    srand(time(NULL));

    int valsSum = 0, currSum = 0;

    mixedValues[0] = initial[randomize()];
    currSum += mixedValues[0];

    int sum = 0;
    for (int v : initial)
        sum += v;

    while (mixedValues.size() < initial.size() - 1) {
        int randIndex = -1;
        int randValue = 0;

        while (randIndex == -1) {
            randIndex = randomize();
            randValue = initial[randIndex];

            for (int v : mixedValues)
                if (v == randValue) {
                    randIndex = -1;
                    break;
                }
        }

        mixedValues.push_back(randValue);
        currSum += randValue;
    }

    mixedValues.push_back(sum - currSum);

    for (int v : mixedValues)
        cout << v << " ";

    cin.get();
    cin.get();
    return 0;
}