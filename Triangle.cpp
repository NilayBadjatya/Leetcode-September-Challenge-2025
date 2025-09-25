class Solution {
public:
    int n;
    int dp[201][201];
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if (row == n) {
            return 0;
        }
        if (dp[row][col] != 1e9) {
            return dp[row][col];
        }
        int sum = triangle[row][col] + min(solve(triangle, row + 1, col),
                                           solve(triangle, row + 1, col + 1));
        return dp[row][col] = sum;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                dp[i][j] = 1e9;
            }
        }
        return solve(triangle, 0, 0);
    }
};
