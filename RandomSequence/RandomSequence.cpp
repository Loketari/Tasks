#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> initial {1, 2, 3, 4, 50, 6, 33, 8, 9, 1000, 11};

int randomize()
{
    return rand() % (initial.size());
}

int findLastInd(vector<int>mixedInd1)
{
	int sumFin = 0;
	for (int i = 0; i < initial.size(); ++i)
		sumFin += initial.size() - (1 + i);

	int sumCur = 0;
	for (int is = 0; is < mixedInd1.size(); ++is) {
		sumCur += mixedInd1[is];
	}

	return sumFin - sumCur;
}

vector<int> sequenceBuilder(vector<int> mixedInd)
{
    vector<int> shuffled(initial.size());
    for (int ind = 0; ind < initial.size(); ++ind) {
        shuffled[ind] = initial[mixedInd[ind]];
    }
    return shuffled;
}

int main()
{
    vector<int> mixedIndices(1);
    srand(time(NULL));

    mixedIndices[0] = randomize();

    while (mixedIndices.size() < initial.size() - 1) {
        int randIndex = -1;

        while (randIndex == -1) {
            randIndex = randomize();

            for (int i = 0; i < mixedIndices.size(); ++i) {
                if (mixedIndices[i] == randIndex) {
                    randIndex = -1;
                }
                if (randIndex == -1) 
                    break;
            }
        }
        mixedIndices.push_back(randIndex);
    }

	mixedIndices.push_back(findLastInd(mixedIndices));

    vector<int> finSeque = sequenceBuilder(mixedIndices);

    for (int ii = 0; ii < finSeque.size(); ++ii)
    cout << finSeque[ii] << " ";

    cin.get();
    cin.get();
    return 0;
}