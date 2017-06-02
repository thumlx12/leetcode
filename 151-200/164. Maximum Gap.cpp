class Solution164 {
public:
int maximumGap(vector<int> &nums) {
    const int n = nums.size();
    if (n < 2) {
        return 0;
    }
    int maxNum = nums[0];
    int minNum = nums[0];
    for (int i = 0; i < n; ++i) {
        maxNum = max(nums[i], maxNum);
        minNum = min(nums[i], minNum);
    }
    if (maxNum == minNum) {
        return 0;
    }
    vector<vector<int>> barrels(n, vector<int>(0));
    for (int i = 0; i < n; ++i) {
        int idx = ((long long)(n - 1)) * (nums[i] - minNum) / (maxNum - minNum);
        barrels[idx].push_back(nums[i]);
    }
    int maxGap = 0;
    vector<int> endPoints;
    for (int i = 0; i < n; ++i) {
        if (barrels[i].empty()) {
            continue;
        } else {
            int left = barrels[i][0];
            int right = barrels[i][0];
            for (int j = 0; j < barrels[i].size(); ++j) {
                left = min(left, barrels[i][j]);
                right = max(right, barrels[i][j]);
            }
            endPoints.push_back(left);
            endPoints.push_back(right);
        }
    }
    for (int i = 1; i < endPoints.size() - 1; i = i + 2) {
        maxGap = max(maxGap, endPoints[i + 1] - endPoints[i]);
    }
    return maxGap;
}

};
