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

int reverse(int x) {
    int ans = 0;
    while (x) {
        int temp = ans * 10 + x % 10;
        if (temp / 10 != ans)
            return 0;
        ans = temp;
        x /= 10;
    }
    return ans;

}

//int main() {
//    int x = 123;
//    int y = -2147483648;
//    cout << reverse(x) << endl;
//    cout << reverse(y) << endl;
//}
