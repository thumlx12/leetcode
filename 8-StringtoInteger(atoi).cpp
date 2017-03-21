//
// Created by sensetime on 3/21/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int myAtoi(string str) {
    if (str.length() <= 0) {
        return NULL;
    }
    bool isPositive = true;
    int startP = 0;
    for (int i = 0;; ++i) {
        if (isdigit(str[i])) {
            startP = i;
            break;
        } else if (str[i] == ' ') {
            continue;
        } else if (str[i] == '+') {
            startP = ++i;
            break;
        } else if (str[i] == '-') {
            startP = ++i;
            isPositive = false;
            break;
        } else {
            return NULL;
        }
    }
    int result = 0;
    for (int i = startP; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            int tmp = result;
            if (isPositive) {
                result *= 10;
                result += str[i] - 48;
                if (result / 10 != tmp) {
                    return INT_MAX;
                }
            } else {
                result *= 10;
                result -= str[i] - 48;
                if (result / 10 != tmp) {
                    return INT_MIN;
                }
            }

        } else {
            break;
        }
    }
    return result;
};

int main() {
    string x = "-2147483647";
    string y = "2147483649";
    cout << myAtoi(x) << endl;
    cout << myAtoi(y) << endl;
}
