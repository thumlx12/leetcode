//
// Created by maolixuan on 2017/6/5.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if(!root){
            return view;
        }
        vector<TreeNode *> nodeVec;
        nodeVec.push_back(root);
        int first=0;
        int last=0;
        bool isFirst=true;
        while(first<nodeVec.size()){
            if(isFirst){
                view.push_back(nodeVec[first]->val);
                isFirst=false;
            }
            if(nodeVec[first]->right){
                nodeVec.push_back(nodeVec[first]->right);
            }
            if(nodeVec[first]->left){
                nodeVec.push_back(nodeVec[first]->left);
            }
            if(first==last){
                first++;
                last=nodeVec.size()-1;
                isFirst=true;
            }else{
                first++;
            }
        }
        return view;
    }
};