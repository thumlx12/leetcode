//
// Created by sensetime on 5/25/17.
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
#include <queue>
#include <list>
#include <unordered_set>
#include <map>

using namespace std;

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a % b);
}

int maxPoints(vector<Point> &points) {
    int maxPoint = -1;

    for (int i = 0; i < points.size(); ++i) {
        map<pair<int, int>, int> countTable;
        int samePoint = 1;
        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                samePoint++;
                continue;
            }
            int dx = points[i].x - points[j].x;
            int dy = points[i].y - points[j].y;
            int gcd = GCD(dy, dx);
            countTable[{dx / gcd, dy / gcd}]++;
        }
        maxPoint = max(maxPoint, samePoint);
        for (auto iter = countTable.begin(); iter != countTable.end(); ++iter) {
            maxPoint = max(maxPoint, iter->second + samePoint);
        }
    }
    return maxPoint;
}

