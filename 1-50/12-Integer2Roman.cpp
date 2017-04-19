//
// Created by sensetime on 3/25/17.
//

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

#define abs(x, y) ((x)>=(y))?((x)-(y)):((y)-(x))

string intToRoman(int num) {
    const vector<int> roman_unit_ten = {1000, 100, 10, 1};
    const vector<int> roman_unit_five = {500, 50, 5};
    const vector<char> roman_char_ten = {'M', 'C', 'X', 'I'};
    const vector<char> roman_char_five = {'D', 'L', 'V'};
    string roman_numeral = "";
    if (num >= 1000) {
        for (int k = 0; k < num / roman_unit_ten[0]; ++k) {
            roman_numeral += roman_char_ten[0];
        }
        num -= (num / roman_unit_ten[0]) * roman_unit_ten[0];
    }
    for (int i = 1, j = 0; i < 4; ++i, ++j) {
        int ten_num = num / roman_unit_ten[i];
        switch (ten_num) {
            case 9: {
                roman_numeral += roman_char_ten[i];
                roman_numeral += +roman_char_ten[i - 1];
                break;
            }
            case 6: {
                roman_numeral += roman_char_five[j];
                roman_numeral += roman_char_ten[i];
                break;
            }
            case 4: {
                roman_numeral += roman_char_ten[i];
                roman_numeral += +roman_char_five[j];
                break;
            }
            default: {
                if (num / roman_unit_five[j]) {
                    roman_numeral += roman_char_five[j];
                    for (int k = 0; k < ten_num - 5; ++k) {
                        roman_numeral += roman_char_ten[i];
                    }
                } else {
                    for (int k = 0; k < ten_num; ++k) {
                        roman_numeral += roman_char_ten[i];
                    }
                }
                break;
            }
        }
        num -= ten_num * roman_unit_ten[i];
    }
    return roman_numeral;
}

//int main() {
//    string roman_num = "{";
//    for (int i = 1; i <= 3999; ++i) {
//        roman_num += "\"";
//        roman_num += intToRoman(i);
//        if (i == 3999) {
//            roman_num += "\"";
//        } else {
//            roman_num += "\",";
//        }
//    }
//    roman_num += "}";
//    cout << roman_num << endl;
//
//}