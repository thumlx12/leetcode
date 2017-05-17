//
// Created by sensetime on 5/17/17.
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
#include <bits/unordered_set.h>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int savedGas = 0;
    int costGas = 0;
    for (int i = 0; i < gas.size(); ++i) {
        savedGas += gas[i];
        costGas += cost[i];
    }
    if (savedGas < costGas) {
        return -1;
    }
    int total = gas.size();
    int k = 0, t = 0;
    for (k = 0; k < gas.size(); k += t) {
        savedGas = 0;
        costGas = 0;
        for (t = 0; t < total;) {
            int station = (k + t) % total;
            savedGas += gas[station];
            costGas += cost[station];
            ++t;
            if (savedGas < costGas) {
                break;
            }
        }
        if (t >= total) {
            return k;
        }
    }
}

//int main() {
//    vector<int> gas = {1, 2};
//    vector<int> cost = {2, 1};
//    cout << canCompleteCircuit(gas, cost);
//}