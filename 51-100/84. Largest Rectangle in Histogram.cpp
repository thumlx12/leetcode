//
// Created by sensetime on 4/21/17.
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

struct BigRect {
    int num;
    int height;

    BigRect(int x, int y) : num(x), height(y) {}
};

int largestRectangleArea(vector<int> &heights) {
    if (heights.size() <= 0) {
        return 0;
    }
    const int size = heights.size();
    heights.insert(heights.begin(), -1);
    heights.push_back(-1);
    stack<BigRect> s;
    int num = 0;
    int mHeight = INT_MAX;
    for (int i = 1; i <= size; ++i) {
        if (heights[i - 1] < heights[i]) {
            num++;
            mHeight = heights[i] < mHeight ? heights[i] : mHeight;
        }
        if (heights[i + 1] < heights[i]) {
            BigRect oneRect(num, mHeight);
            s.push(oneRect);
            num = 0;
            mHeight = INT_MAX;
        }
    }
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    largestRectangleArea(heights);
}
