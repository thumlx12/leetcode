//
// Created by sensetime on 3/20/17.
//

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

string convert(string s, int numRows) {
    if (s.length() <= numRows || s.length() <= 2 || numRows <= 1) {
        return s;
    }
    int unitLength = 2 * numRows - 2;
    const int length = s.length();
    vector<string> strLayer(numRows);
    for (int i = 0; i < length; ++i) {
        int unitIndex = (i - (i / unitLength) * unitLength);
        int layerIndex;
        if (unitIndex < numRows) {
            layerIndex = unitIndex - (unitIndex / numRows);
        } else {
            layerIndex = numRows - 2 - unitIndex % numRows;
        }
        strLayer[layerIndex] += (s[i]);
    }
    string convertedStr;
    for (int i = 0; i < numRows; ++i) {
        convertedStr += strLayer[i];
    }
    return convertedStr;
}

//int main() {
//    string s = "PAYPALISHIRING";
//    cout << convert(s, 3);
//}

