//
// Created by sensetime on 4/8/17.
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


bool isMatch(string s, string p) {
    bool *f[2];
    int lens = s.size();
    int lenp = p.size();
    f[0] = new bool[lenp + 1];
    f[1] = new bool[lenp + 1];
    f[0][0] = true;
    for (int i = 1; i <= lenp; ++i)
        if (p[i - 1] == '*')
            f[0][i] = f[0][i - 1];
        else
            f[0][i] = false;
    bool now = false;
    for (int i = 1; i <= lens; ++i) {
        now = !now;
        f[now][0] = false;
        for (int j = 1; j <= lenp; ++j)
            switch (p[j - 1]) {
                case '*':
                    f[now][j] = f[!now][j - 1] || f[!now][j] || f[now][j - 1];
                    break;
                case '?':
                    f[now][j] = f[!now][j - 1];
                    break;
                default:
                    f[now][j] = f[!now][j - 1] && (s[i - 1] == p[j - 1]);
                    break;
            }
    }
    return f[now][lenp];
}