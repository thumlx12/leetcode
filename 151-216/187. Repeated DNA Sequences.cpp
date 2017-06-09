//
// Created by maolixuan on 2017/6/4.
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

class Solution187 {
public:
    string SeqNum2String(int seq) {
        unordered_map<int, char> Num2Nuc = {{0, 'A'},
                                            {1, 'T'},
                                            {2, 'G'},
                                            {3, 'C'}};
        string seqStr = "";
        int getHeadNuc = 0b00000000000011000000000000000000;
        for (int i = 0; i < 10; ++i) {
            int idx = (seq & getHeadNuc) >> 18;
            seqStr += Num2Nuc[idx];
            seq = seq << 2;
        }
        return seqStr;
    }

    vector<string> findRepeatedDnaSequences_BitOperation(string s) {
        vector<string> ret;
        if (s.length() <= 10) {
            return ret;
        }
        unordered_map<char, int> Nuc2Num = {{'A', 0},
                                            {'T', 1},
                                            {'G', 2},
                                            {'C', 3}};
        unordered_map<int, int> seqMap;
        int seqInNum = 0;
        for (int i = 0; i < 10; ++i) {
            seqInNum = seqInNum | Nuc2Num[s[i]];
            if (i < 9) {
                seqInNum = seqInNum << 2;
            }
        }
        seqMap[seqInNum]++;
        int cutHead = 0b00000000000000111111111111111111;
        for (int i = 10; i <= s.length() - 1; ++i) {
            seqInNum = seqInNum & cutHead;
            seqInNum = seqInNum << 2;
            seqInNum = seqInNum | Nuc2Num[s[i]];
            seqMap[seqInNum]++;
        }
        for (unordered_map<int, int>::const_iterator iter = seqMap.begin(); iter != seqMap.end(); ++iter) {
            if ((*iter).second > 1) {
                ret.push_back(SeqNum2String((*iter).first));
            }
        }
        return ret;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.length() <= 10) {
            return ret;
        }
        unordered_map<string, int> seqMap;
        for (int i = 0; i <= s.length() - 10; ++i) {
            string DNA_seq = s.substr(i, 10);
            seqMap[DNA_seq]++;
        }

        for (unordered_map<string, int>::const_iterator iter = seqMap.begin(); iter != seqMap.end(); ++iter) {
            if ((*iter).second > 1) {
                ret.push_back((*iter).first);
            }
        }
        return ret;
    }
};

//int main() {
//    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
//    Solution187 *solu;
//    vector<string> ValidSeqs = solu->findRepeatedDnaSequences_BitOperation(s);
//    for (int i = 0; i < ValidSeqs.size(); ++i) {
//        cout << ValidSeqs[i] << "\n";
//    }
//    unsigned int seqInNum = 0;
//    for (int i = 0; i < 10; ++i) {
//        cout << bitset<20>(seqInNum) << endl;
//        unsigned int num = Nuc2Num[s[i]];
//        seqInNum = seqInNum | num;
//        cout << bitset<20>(seqInNum) << endl;
//        if (i < 9) {
//            seqInNum = seqInNum << 2;
//        }
//        cout << bitset<20>(seqInNum) << endl;
//        cout << "-----------------------------" << endl;
//    }
//    cout << bitset<32>(seqInNum) << endl;;
//}
