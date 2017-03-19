//
// Created by jackie on 3/19/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

/*
 * int findKth(int k, vector<int> &nums1, int lo1, vector<int> &nums2, int lo2) {
    if ((nums1.size() - lo1) > (nums2.size() - lo2)) {
        return findKth(k, nums2, lo2, nums1, lo1);
    }
    if ((nums1.size() - lo1) <= 0) {
        return nums2[lo2 + k - 1];
    }
    if (k <= 1) {
        return min(nums1[lo1], nums2[lo2]);
    }
    int pa = min(lo1 + k / 2 - 1, nums1.size());
    int pb = min(lo2 + k / 2 - 1, nums2.size());
    if (nums1[pa] < nums2[pb]) {
        return findKth(k - k / 2, nums1, pa + 1, nums2, lo2);
    } else {
        return findKth(k - k / 2, nums1, lo1, nums2, pb + 1);
    }
}
 */


int findKth(int k, vector<int> &nums1, int lo1, vector<int> &nums2, int lo2) {

    if (nums1.size() <= lo1) {
        return nums2[lo2 + k - 1];
    }
    if (nums2.size() <= lo2) {
        return nums1[lo1 + k - 1];
    }
    if (k <= 1) {
        return nums1[lo1] < nums2[lo2] ? nums1[lo1] : nums2[lo2];
    }

    int A_kth = ((lo1 + k / 2 - 1) < nums1.size()) ? nums1[lo1 + k / 2 - 1] : INT_MAX;
    int B_kth = ((lo2 + k / 2 - 1) < nums2.size()) ? nums2[lo2 + k / 2 - 1] : INT_MAX;
    if (A_kth < B_kth) {
        return findKth(k - k / 2, nums1, lo1 + k / 2, nums2, lo2);
    } else {
        return findKth(k - k / 2, nums1, lo1, nums2, lo2 + k / 2);
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int total = nums1.size() + nums2.size();
    if (total & 0x1) {
        return findKth(total / 2 + 1, nums1, 0, nums2, 0);
    } else {
        double median =
                ((double) findKth(total / 2, nums1, 0, nums2, 0) +
                 findKth(total / 2 + 1, nums1, 0, nums2, 0)) / 2;
        return median;
    }
}

int main() {
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    cout << findMedianSortedArrays(a, b) << endl;

    vector<int> a1 = {1, 2};
    vector<int> b1 = {1, 2};
    cout << findMedianSortedArrays(a1, b1) << endl;

    vector<int> a2 = {1};
    vector<int> b2 = {2, 3, 4, 5, 6};
    cout << findMedianSortedArrays(a2, b2) << endl;
}