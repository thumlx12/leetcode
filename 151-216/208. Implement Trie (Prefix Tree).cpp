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

struct TrieNode {
    char val;
    vector<TrieNode *> children;
    bool isWord;

    TrieNode(char x) : val(x), isWord(false) {}
};

class Trie {
private:
    int searchCharInChildren(char c, TrieNode *vec) {
        for (int i = 0; i < vec->children.size(); ++i) {
            if ((vec->children[i])->val == c) {
                return i;
            }
        }
        return -1;
    }

public:
    TrieNode *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('*');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i) {
            int target = searchCharInChildren(word[i], cur);
            if (target != -1) {
                cur = cur->children[target];
            } else {
                TrieNode *newChild = new TrieNode(word[i]);
                cur->children.push_back(newChild);
                cur = newChild;
            }
        }
        cur->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i) {
            int target = searchCharInChildren(word[i], cur);
            if (target == -1) {
                return false;
            } else {
                cur = cur->children[target];
            }
        }
        if (cur->children.empty()) {
            return true;
        } else {
            return cur->isWord;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int target = searchCharInChildren(prefix[i], cur);
            if (target == -1) {
                return false;
            } else {
                cur = cur->children[target];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int binarySeach(int target, int lo, int hi, vector<int> &nums) {
    if (hi - lo < 1) {
        return hi;
    }
    int mi = (hi + lo) / 2;
    if (nums[mi] < target) {
        return binarySeach(target, mi + 1, hi, nums);
    } else {
        return binarySeach(target, lo, mi, nums);
    }
}

//int main() {
////    Trie *obj = new Trie();
////    obj->insert("app");
////    obj->insert("apple");
////    obj->insert("beer");
////    obj->insert("add");
////    obj->insert("jam");
////    obj->insert("rental");
////    cout<<obj->search("apps");
////    cout<<obj->search("app");
//    vector<int> nums = {0, 2, 5, 6, 8, 12, 13};
//    cout << nums[binarySeach(7, 0, nums.size() - 1, nums)];
//}

