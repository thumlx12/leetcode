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

vector<string> splitStr(const string &str, char spec) {
    vector<string> strList;
    string strTemp = str;
    int iSpecIndex = 0;
    while (true) {
        iSpecIndex = strTemp.find_first_of(spec);
        if (iSpecIndex < 0)
            break;
        string strFront = strTemp.substr(0, iSpecIndex);
        strTemp = strTemp.substr(iSpecIndex + 1, strTemp.size() - iSpecIndex - 1);
        if (strFront.size() > 0)
            strList.push_back(strFront);
    }
    if (strTemp.size() > 0) {
        strList.push_back(strTemp);
    }
    return strList;
}

string simplifyPath(string path) {
    if (path.length() <= 1) {
        return path;
    }
    vector<string> split = splitStr(path, '/');
    vector<string> oppo_stack;
    for (int i = 0; i < split.size(); ++i) {
        if (split[i] == ".") {
            continue;
        } else if (split[i] == "..") {
            if (!oppo_stack.empty()) {
                oppo_stack.pop_back();
            }
        } else {
            oppo_stack.push_back(split[i]);
        }
    }
    string ret = "/";
    for (int i = 0; i < oppo_stack.size(); ++i) {
        if (i < oppo_stack.size() - 1) {
            ret += oppo_stack[i] + "/";
        } else {
            ret += oppo_stack[i];
        }
    }
    return ret;
}

//int main() {
//    string str = "///";
//    cout << simplifyPath(str) << endl;
//}
