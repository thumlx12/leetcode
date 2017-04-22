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

int largestRectangleArea(vector<int> &heights) {
    if (heights.size() <= 0) {
        return 0;
    }
    stack<int> bar;
    heights.push_back(-1);
    int maxArea = -1;
    int h, w;
    for (int i = 0; i < heights.size(); ++i) {
        if (!bar.empty() && heights[i] <= heights[bar.top()]) {
            while (!bar.empty() && heights[i] <= heights[bar.top()]) {
                h = heights[bar.top()];
                bar.pop();
                w = bar.empty() ? i : (i - bar.top() - 1);
                maxArea = max(maxArea, h * w);
            }
        }
        bar.push(i);
    }
    return maxArea;
}

//int main() {
//    vector<int> heights = {2, 1, 5, 6, 2, 3};
//    cout << largestRectangleArea(heights);
//}
