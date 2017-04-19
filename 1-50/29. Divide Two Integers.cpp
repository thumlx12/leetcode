//
// Created by sensetime on 3/27/17.
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

using namespace std;

int divide(int divided, int dividor) {
    if (dividor == 0) {
        return INT_MAX;
    }
    if (abs((long long) divided) < abs((long long) dividor)) {
        return 0;
    }
    long long L_divided = abs((long long) divided);

    long long final_result = 0;
    while (L_divided > 0) {
        long long result = 1;
        long long L_dividor = abs((long long) dividor);
        while (L_divided >= L_dividor) {
            L_dividor <<= 1;
            result <<= 1;
        }
        L_divided -= (L_dividor >> 1);
        final_result += (result >> 1);
    }
    if ((divided < 0 && dividor > 0) || (divided > 0 && dividor < 0)) {
        if (-final_result < INT_MIN) {
            return INT_MAX;
        } else {
            return (int) (-final_result);
        }
    } else {
        if (final_result > INT_MAX) {
            return INT_MAX;
        } else {
            return (int) final_result;
        }
    }
}

//int main() {
//    unordered_map<string, bool> map1;
//    map1.insert(make_pair("boo", false));
//    map1.insert(make_pair("for", false));
//    map1.insert(make_pair("tim", false));
//    if (map1["boo"] == NULL) {
//        cout << "null" << endl;
//    }
//}