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

string simplifyPath(string path) {
    if (path.length() <= 1) {
        return path;
    }
    for (int i = path.length() - 1; (path[i] == '/' || path[i] == '.') && (0 < i); --i) {
        path.erase(path.length() - 1, 1);
    }
    int slash_count = 0;
    int lastSlashIndex = -1;
    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == '/') {
            slash_count++;
            lastSlashIndex = i;
        }
    }
    if (slash_count <= 1) {
        return path;
    } else {
        return path.substr(lastSlashIndex);
    }
}

int main() {
    string str = "/.";
    cout << simplifyPath(str);
}
