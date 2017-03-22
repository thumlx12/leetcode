//
// Created by sensetime on 3/22/17.
//

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> get8Index(int size) {
    vector<int> index;

    int count = 0;

    while (count < 8) {
        int randomIndex = rand() % size;
        if (find(index.begin(), index.end(), randomIndex) != index.end())
            continue;

        index.push_back(randomIndex);
        count++;
    }

    return index;
}

vector<string> get8Path(vector<string> current_images, string input_root) {
    vector<string> path8;

    if (current_images.size() <= 8) {
        for (int i = 0; i < current_images.size(); ++i) {
            path8.push_back(input_root + current_images[i]);
        }
        for (int i = 0, j = current_images.size(); j < 8; ++i, ++j) {
            path8.push_back(input_root + current_images[i]);
        }

    } else {
        vector<int> index = get8Index(current_images.size());
        for (int i = 0; i < index.size(); ++i) {
            path8.push_back(input_root + current_images[index[i]]);
        }
    }

    return path8;
}

//int main() {
//    vector<string> current_images = {"1", "2", "3", "4","5"};
//    string input_root = "image/";
//    vector<string> result = get8Path(current_images, input_root);
//    for (int i = 0; i < result.size(); ++i) {
//        cout << result[i] << endl;
//    }
//    cout << result.size();
//}