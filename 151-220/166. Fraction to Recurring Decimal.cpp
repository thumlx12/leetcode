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

using namespace std;

class Solution166 {
public:
    long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    string fractionToDecimal(long numerator, long denominator) {
        if (denominator == 0) {
            return "";
        }
        if (numerator == 0) {
            return "0";
        }
        bool isPostive = (numerator * denominator > 0);
        numerator = numerator > 0 ? numerator : -numerator;
        denominator = denominator > 0 ? denominator : -denominator;
        string fraction = "";
        if (!isPostive) {
            fraction += '-';
        }
        long GCD = gcd(numerator, denominator);
        if (GCD == denominator) {
            fraction += to_string(numerator / denominator);
            return fraction;
        }
        numerator /= GCD;
        denominator /= GCD;
        long integerPart = numerator / denominator;
        numerator = numerator % denominator;
        bool isLimit = false;
        int circlePos = 0;
        vector<int> eachDigit;
        map<pair<int, int>, int> leftMap;
        for (int i = 0;; ++i) {
            int tmp1 = (numerator * 10) / denominator;
            int tmp2 = (numerator * 10) % denominator;
            if (leftMap.count({tmp1, tmp2})) {
                circlePos = leftMap[{tmp1, tmp2}];
                break;
            } else {
                leftMap[{tmp1, tmp2}] = i;
            }
            eachDigit.push_back(tmp1);
            if (tmp2 == 0) {
                isLimit = true;
                break;
            }
            numerator = tmp2;
        }
        fraction += to_string(integerPart) + '.';
        if (isLimit) {
            for (int k = 0; k < eachDigit.size(); ++k) {
                fraction += (eachDigit[k] + 48);
            }
        } else {
            for (int k = 0; k < circlePos; ++k) {
                fraction += (eachDigit[k] + 48);
            }
            fraction += '(';
            for (int t = circlePos; t < eachDigit.size(); ++t) {
                fraction += (eachDigit[t] + 48);
            }
            fraction += ')';
        }
        return fraction;
    }

    string fractionToDecimal(int numerator, int denominator) {
        long num1 = numerator;
        long num2 = denominator;
        return fractionToDecimal(num1, num2);
    }
};

//int main() {
//    Solution166 *solu;
//    int a = -50;
//    int b = 8;
//    cout << solu->fractionToDecimal(a, b);
//}
