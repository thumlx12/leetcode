//
// Created by sensetime on 5/16/17.
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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

class Solution133 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return node;
        }
        UndirectedGraphNode *newStart = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> BFS_queue;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hf;
        BFS_queue.push(node);
        hf[node] = newStart;
        while (!BFS_queue.empty()) {
            UndirectedGraphNode *current = BFS_queue.front();
            UndirectedGraphNode *cpCurrent = hf[current];
            BFS_queue.pop();
            for (int i = 0; i < current->neighbors.size(); ++i) {
                if (hf.count(current->neighbors[i]) > 0) {
                    cpCurrent->neighbors.push_back(hf[current->neighbors[i]]);
                } else {
                    BFS_queue.push(current->neighbors[i]);
                    UndirectedGraphNode *newNeighbor = new UndirectedGraphNode(current->neighbors[i]->label);
                    cpCurrent->neighbors.push_back(newNeighbor);
                    hf[current->neighbors[i]] = newNeighbor;
                }
            }
        }
        return hf[node];
    }
};

//int main() {
//    UndirectedGraphNode *n0 = new UndirectedGraphNode(0);
//    UndirectedGraphNode *n1 = new UndirectedGraphNode(1);
//    UndirectedGraphNode *n2 = new UndirectedGraphNode(2);
//    UndirectedGraphNode *n3 = new UndirectedGraphNode(3);
//    UndirectedGraphNode *n4 = new UndirectedGraphNode(4);
//    UndirectedGraphNode *n5 = new UndirectedGraphNode(5);
//
//    n0->neighbors.push_back(n1);
//    n0->neighbors.push_back(n5);
//    n1->neighbors.push_back(n2);
//    n1->neighbors.push_back(n5);
//    n2->neighbors.push_back(n3);
//    n3->neighbors.push_back(n4);
//    n3->neighbors.push_back(n4);
//    n4->neighbors.push_back(n5);
//    n4->neighbors.push_back(n5);
//
//    Solution133 *solu = new Solution133();
//    UndirectedGraphNode *newClone = solu->cloneGraph(n0);
//    cout << endl;
//}