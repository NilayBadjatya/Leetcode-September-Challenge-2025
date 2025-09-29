class Solution {

    public int solve(int[] values, int i, int j, int[][] dp) {
        if (i+1 == j) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int sum = Integer.MAX_VALUE;
        for (int k = i + 1; k < j; k++) {
            int tempSum = values[i] * values[k] * values[j]
                    + solve(values, i, k, dp) + solve(values, k, j, dp);
            sum = Math.min(sum, tempSum);
        }
        return dp[i][j] = sum;
    }

    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(values, 0, n - 1, dp);
    }
}
