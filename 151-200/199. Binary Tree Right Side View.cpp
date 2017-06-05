//
// Created by maolixuan on 2017/6/5.
//

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