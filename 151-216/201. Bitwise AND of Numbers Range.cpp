//
// Created by sensetime on 6/8/17.
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
#include <map>
#include <bitset>

using namespace std;

class Solution201 {
public:
    int rangeBitwiseAnd(int m, int n) {

        return (n > m) ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : n;

    }
};
