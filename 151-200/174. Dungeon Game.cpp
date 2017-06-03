class Solution174 {
public:
    int m;
    int n;
    /* DFS -- too slow
    int maxLowestHP = INT_MIN;

    void getMaxLowestHP(vector <vector<int>> &dungeon, int lowestHP, int currentHP, int x, int y) {
        currentHP += dungeon[x][y];
        lowestHP = min(lowestHP, currentHP);
        if (x == m - 1 && y == n - 1) {
            maxLowestHP = max(lowestHP, maxLowestHP);
            return;
        }
        if (x + 1 < m) {
            getMaxLowestHP(dungeon, lowestHP, currentHP, x + 1, y);
        }
        if (y + 1 < n) {
            getMaxLowestHP(dungeon, lowestHP, currentHP, x, y + 1);
        }
    } */

    int calculateMinimumHP(vector <vector<int>> &dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        vector <vector<int>> minHPNeeded(2, vector<int>(n, 0));
        minHPNeeded[1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : -dungeon[m - 1][n - 1] + 1;
        for (int j = n - 2; 0 <= j; --j) {
            minHPNeeded[1][j] = max(1, minHPNeeded[1][j + 1] - dungeon[m - 1][j]);
        }
        bool current = true;
        for (int i = m - 2; 0 <= i; --i) {
            current = !current;
            minHPNeeded[current][n - 1] = max(1, minHPNeeded[!current][n - 1] - dungeon[i][n - 1]);
            for (int j = n - 2; 0 <= j; --j) {
                minHPNeeded[current][j] = min(minHPNeeded[!current][j], minHPNeeded[current][j + 1]) - dungeon[i][j];
                minHPNeeded[current][j] = max(1, minHPNeeded[current][j]);
            }
        }
        return minHPNeeded[current][0];
    }

};
