class Solution153 {
public:
    int findPivot(vector<int> &nums, int lo, int hi) {
        if (hi - lo < 1) {
            return lo;
        }
        int mi = (lo + hi) / 2;
        if (nums[lo] <= nums[mi]) {
            if (nums[mi] < nums[mi + 1]) {
                return findPivot(nums, mi + 1, hi);
            } else {
                return mi;
            }
        } else {
            return findPivot(nums, lo, mi - 1);
        }
    }

    int findMin(vector<int> &nums) {
        int pivot = findPivot(nums, 0, nums.size() - 1);
        if (pivot >= nums.size() - 1) {
            return nums[0];
        } else {
            return nums[pivot + 1];
        }
    }
};
