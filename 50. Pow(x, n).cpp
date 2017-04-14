//
// Created by sensetime on 4/11/17.
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

double pow_helper(double x, int abs_n) {
    if (abs_n == 0) {
        return 1;
    }
    if (abs_n == 1) {
        return x;
    }
    if (abs_n == 2) {
        return x * x;
    }
    double halfPow = pow_helper(x, abs_n / 2);
    if (abs_n % 2) {
        return x * halfPow * halfPow;
    } else {
        return halfPow * halfPow;
    }
}

double myPow(double x, int n) {
    if (x == 0) {
        return 0;
    }
    if (n > 0) {
        return pow_helper(x, n);
    } else if (n < 0) {
        return pow_helper(1 / x, -n);
    } else {
        return 1;
    }

}

//int main() {
//    cout << pow(2.00000, -2147483648) << endl;
//}