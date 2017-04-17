//
// Created by sensetime on 4/17/17.
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

string normal_justify(vector<string> &words, int start, int &count, int &currentLength, int &maxWidth) {
    string line = "";
    int extraSpaces = maxWidth - currentLength + 1;
    if (count <= 1) {
        line += words[start] + string(extraSpaces, ' ');
    } else {
        int slots = count - 1;
        int leftSpaces = extraSpaces % slots;
        int averageSpaces = extraSpaces / slots;
        for (int i = start, j = 0; i < start + count - 1; ++i, ++j) {
            line += words[i] + string(averageSpaces + 1, ' ') + ((j < leftSpaces) ? " " : "");
        }
        line += words[start + count - 1];
    }
    return line;
}

string left_justify(vector<string> &words, int start, int &count, int &currentLength, int &maxWidth) {
    string line = "";
    int extraSpaces = maxWidth - currentLength + 1;
    if (count <= 1) {
        line += words[start] + string(extraSpaces, ' ');
    } else {
        for (int i = start; i < start + count - 1; ++i) {
            line += words[i] + " ";
        }
        line += words[start + count - 1] + string(extraSpaces, ' ');
    }
    return line;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    int currentLength = 0;
    int count = 0;
    vector<string> ret;
    for (int i = 0; i < words.size();) {
        if (currentLength + words[i].length() <= maxWidth) {
            currentLength += words[i].length() + 1;
            ++count;
            ++i;
        } else {
            ret.push_back(normal_justify(words, i - count, count, currentLength, maxWidth));
            currentLength = 0;
            count = 0;
        }
    }
    ret.push_back(left_justify(words, words.size() - count, count, currentLength, maxWidth));
    return ret;
}

//int main() {
//    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
//    vector<string> ret = fullJustify(words, 16);
//    for (int i = 0; i < ret.size(); ++i) {
//        cout << ret[i] << endl;
//    }
//}