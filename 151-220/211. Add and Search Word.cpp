//
// Created by sensetime on 6/10/17.
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
#include <unordered_set>
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

class WordDictionary {
private:
    int searchCharInChildren(char c, TrieNode *vec) {
        for (int i = 0; i < vec->children.size(); ++i) {
            if ((vec->children[i])->val == c) {
                return i;
            }
        }
        return -1;
    }

    bool search_recursively(string &word, TrieNode *cur, int start) {
        for (int i = start; i < word.length(); ++i) {
            if (word[i] == '.') {
                bool isFind = false;
                for (int j = 0; !isFind && j < cur->children.size(); ++j) {
                    isFind = search_recursively(word, cur->children[j], i + 1);
                }
                return isFind;
            }
            int target = searchCharInChildren(word[i], cur);
            if (target == -1) {
                return false;
            } else {
                cur = cur->children[target];
            }
        }
        return cur->isWord;
    }

public:
    TrieNode *root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode('*');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_recursively(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

//int main() {
//    WordDictionary *dict = new WordDictionary();
//    dict->addWord("a");
////    dict->addWord("dad");
////    dict->addWord("mad");
//    cout << dict->search("a.");
//}
