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

string multiply_single(string &num1, int f) {
    if (f == 0) {
        return "0";
    }
    stack<char> digits;
    int oneDigit;
    int exceed = 0;
    for (int i = num1.size() - 1; 0 <= i; --i) {
        oneDigit = (num1[i] - 48) * f + exceed;
        digits.push((oneDigit % 10) + 48);
        exceed = oneDigit / 10;
    }
    if (exceed != 0) {
        digits.push(exceed + 48);
    }
    string res = "";
    while (!digits.empty()) {
        res += digits.top();
        digits.pop();
    }
    return res;
}

string myplus(string &num1, string &num2) {
    if (num1.size() < num2.size()) {
        return myplus(num2, num1);
    }
    int oneDigit;
    int exceed = 0;
    stack<char> digits;
    int i = num1.size() - 1, j = num2.size() - 1;
    for (; 0 <= i && 0 <= j; --i, --j) {
        oneDigit = num1[i] + num2[j] - 96 + exceed;
        digits.push((oneDigit % 10) + 48);
        exceed = oneDigit / 10;
    }
    for (; 0 <= i; --i) {
        oneDigit = num1[i] - 48 + exceed;
        digits.push((oneDigit % 10) + 48);
        exceed = oneDigit / 10;
    }
    if (exceed != 0) {
        digits.push(exceed + 48);
    }
    string res = "";
    while (!digits.empty()) {
        res += digits.top();
        digits.pop();
    }
    return res;

}

string multiply(string num1, string num2) {
    if (num1.size() < num2.size()) {
        return multiply(num2, num1);
    }
    string res = multiply_single(num1, num2[num2.size() - 1] - 48);
    int zeroNum = 1;
    for (int j = num2.size() - 2; 0 <= j; --j, ++zeroNum) {
        string tmp = multiply_single(num1, num2[j] - 48) + string(zeroNum, '0');
        res = myplus(res, tmp);
    }
    return res;
}

//int main() {
//    string n1 = "123456";
//    int f = 0;
//    cout << multiply_single(n1, f) << endl;
//
//    string n2 = "10";
//    cout << multiply(n1, n2) << endl;
//}
