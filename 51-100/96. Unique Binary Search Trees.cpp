//
// Created by sensetime on 4/27/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

using namespace std;

int numTrees(int n) {
    vector<int> numBST(n + 1, 0);
    numBST[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
            numBST[i] += numBST[j] * numBST[i - j - 1];
        }
    }
    return numBST[n];
}
