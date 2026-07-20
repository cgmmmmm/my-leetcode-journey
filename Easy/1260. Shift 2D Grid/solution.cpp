class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        // 1. shift at grid[i][j] to grid[i][j + 1] can be established as j + k % (grid[i].size()), and i + ((j + k) / grid[i].size())
        // 2. shift at grid[m-1][n-1] to grid[0][0] is the same as rule1, but if i == m, then i % m

        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n));

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                int dist = j + k;
                int ri = i + (dist / n);
                if (ri >= m) ri %= m;
                int rj = dist % n;
                res[ri][rj] = grid[i][j];
            }
        }

        return res;
    }
};