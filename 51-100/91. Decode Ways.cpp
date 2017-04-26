//
// Created by sensetime on 4/26/17.
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

void getAmount_recursive(string &s, int &count, int start) {
    if (start > s.length() - 1) {
        count++;
        return;
    }
    int oneDigitNum = (s[start] - 48);
    if (0 < oneDigitNum && oneDigitNum <= 9) {
        getAmount_recursive(s, count, start + 1);
        if (s.length() - start > 1) {
            int twoDigitsNum = (s[start] - 48) * 10 + (s[start + 1] - 48);
            if (0 < twoDigitsNum && twoDigitsNum <= 26) {
                getAmount_recursive(s, count, start + 2);
            }
        }
    }
}

int getAmount_fib(string &s, int end) {
    int first = (0 < (s[0] - 48)) ? 1 : 0;
    if (s.length() == 1 || !first) {
        return first;
    }
    int second = 1;
    int tmp = (s[0] - 48) * 10 + (s[1] - 48);
    if (s[1] - 48 == 0) {
        if (tmp > 26) {
            return 0;
        }
    } else {
        if (tmp <= 26) {
            second = 2;
        }
    }

    int start = 2;
    int count = second;
    for (; start <= end; ++start) {
        int part1 = 0;
        int part2 = 0;
        if (0 < s[start - 1] - 48) {
            int twoDigits = (s[start - 1] - 48) * 10 + (s[start] - 48);
            if (0 < twoDigits && twoDigits <= 26) {
                part2 = first;
            }
        }
        if (s[start] - 48 > 0) {
            part1 = second;
        }
        if (!(part1 || part2)) {
            return 0;
        }
        count = part1 + part2;
        first = second;
        second = count;
    }
    return count;
}

int numDecodings(string s) {
    if (s.length() <= 0) {
        return 0;
    }
    for (int i = 0; i < s.length(); ++i) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return getAmount_fib(s, s.length() - 1);
}

//int main() {
//    string s = "10";
//    cout << numDecodings(s);
//}
