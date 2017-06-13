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
    TrieNode *children[26];
    bool isWord;

    TrieNode(char x) : val(x), isWord(false) {
        fill_n(this->children, 26, nullptr);
    }
};

class Trie {
private:
    TrieNode *searchCharInChildren(char c, TrieNode *vec) {
        return vec->children[c - 97];
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
            TrieNode *target = searchCharInChildren(word[i], cur);
            if (target) {
                cur = target;
            } else {
                TrieNode *newChild = new TrieNode(word[i]);
                cur->children[word[i] - 97] = newChild;
                cur = newChild;
            }
        }
        cur->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i) {
            TrieNode *target = searchCharInChildren(word[i], cur);
            if (!target) {
                return false;
            } else {
                cur = target;
            }
        }
        return cur->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix, TrieNode *&cur) {
        for (int i = 0; i < prefix.length(); ++i) {
            TrieNode *target = searchCharInChildren(prefix[i], cur);
            if (!target) {
                return false;
            } else {
                cur = target;
            }
        }
        return true;
    }
};

class Solution212 {
public:

    int m;
    int n;
    Trie *trieTree;
    unordered_set<string> existWordSet;

    void searchWord_DFS(vector<vector<char>> &board, vector<vector<bool>> &isUsedChar,
                        string current, int pos_x, int pos_y) {
        isUsedChar[pos_x][pos_y] = true;
        current += board[pos_x][pos_y];
        TrieNode *start = trieTree->root;
        if (!trieTree->startsWith(current, start)) {
            isUsedChar[pos_x][pos_y] = false;
            return;
        }
        if (start->isWord) {
            existWordSet.insert(current);
        }
        //up
        if (pos_x - 1 >= 0 && !isUsedChar[pos_x - 1][pos_y]) {
            searchWord_DFS(board, isUsedChar, current, pos_x - 1, pos_y);
        }
        //left
        if (pos_y - 1 >= 0 && !isUsedChar[pos_x][pos_y - 1]) {
            searchWord_DFS(board, isUsedChar, current, pos_x, pos_y - 1);
        }
        //down
        if (pos_x + 1 < board.size() && !isUsedChar[pos_x + 1][pos_y]) {
            searchWord_DFS(board, isUsedChar, current, pos_x + 1, pos_y);
        }
        //right
        if (pos_y + 1 < board[0].size() && !isUsedChar[pos_x][pos_y + 1]) {
            searchWord_DFS(board, isUsedChar, current, pos_x, pos_y + 1);
        }
        isUsedChar[pos_x][pos_y] = false;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> ans;
        m = board.size();
        if (m <= 0) {
            return ans;
        }
        n = board[0].size();
        if (n <= 0) {
            return ans;
        }
        trieTree = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            trieTree->insert(words[i]);
        }
        vector<vector<bool>> isUsedChar(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                searchWord_DFS(board, isUsedChar, "", i, j);
            }
        }
        for (unordered_set<string>::const_iterator iter = existWordSet.begin(); iter != existWordSet.end(); ++iter) {
            ans.push_back(*iter);
        }
        return ans;
    }
};

//int main() {
//    vector<TrieNode *> children(26, NULL);
//}