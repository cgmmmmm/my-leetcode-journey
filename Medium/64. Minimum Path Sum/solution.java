class Solution {
    public int dfs(int i, int j, int[][] dp, final int m, final int n, final int[][] grid)
    {
        if (i >= m || j >= n) return (int)1e9;
        if (i == m-1 && j == n-1) return grid[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int down = dfs(i+1, j, dp, m, n, grid);
        int right = dfs(i, j+1, dp, m, n, grid);

        dp[i][j] = grid[i][j] + Math.min(down, right);

        return dp[i][j];
    }

    public int minPathSum(int[][] grid) 
    {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        for (int[] arr : dp)
        {
            Arrays.fill(arr, -1);
        }

        return dfs(0, 0, dp, m, n, grid);
    }
}