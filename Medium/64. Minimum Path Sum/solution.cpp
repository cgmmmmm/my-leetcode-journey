class Solution {
public:
    int dfs(int i, int j, 
        std::vector<std::vector<int>>& dp,
        const int m, const int n,
        const std::vector<std::vector<int>>& grid)
    {
        if (i >= m || j >= n) return INT_MAX;

        if (i == m-1 && j == n-1) return grid[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int down = dfs(i+1, j, dp, m, n, grid);
        int bottom = dfs(i, j+1, dp, m, n, grid);

        dp[i][j] = grid[i][j] + std::min(down, bottom);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));

        return dfs(0, 0, dp, m, n, grid);
    }
};