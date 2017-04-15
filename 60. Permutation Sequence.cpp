//
// Created by sensetime on 4/15/17.
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

vector<int> factorial_arr = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

char findKthAvailable(vector<bool> &usedDigit, int k) {
    int p = 0, t = 0;
    for (; t <= k; ++p) {
        if (!usedDigit[p]) {
            ++t;
        }
    }
    usedDigit[p - 1] = true;
    return ((char) (p + 48));
}

string getPermutation(int n, int k) {
    string KthPermutation = "";
    vector<bool> usedDigit(n, false);
    int tmp1 = k;
    for (int count = 0, cur = n - 1; count < n; ++count, --cur) {
        int tmp2 = tmp1;
        int Nth_num = 0;
        for (; tmp2 > factorial_arr[cur]; ++Nth_num) {
            tmp2 -= factorial_arr[cur];
        }
        KthPermutation += findKthAvailable(usedDigit, Nth_num);
        tmp1 = tmp2;
    }
    return KthPermutation;
}

//int main() {
//    int n = 4;
//    for (int k = 1; k <= factorial_arr[n]; ++k)
//        cout << getPermutation(n, k) << endl;
//}