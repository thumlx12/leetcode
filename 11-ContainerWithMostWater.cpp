//
// Created by sensetime on 3/24/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int maxArea(vector<int> &height) {
    int i = 0;
    int j = height.size() - 1;
    int area = 0;
    while (i < j) {
        int minH = height[i] > height[j] ? height[j] : height[i];
        int newArea = ((j - i) * minH);
        area = (area >= newArea) ? area : newArea;
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return area;
}

//int main() {
//    vector<int> height = {1, 2, 1};
//    cout << maxArea(height);
//}