class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int m = matrix.size();
        std::vector<int> res(m, 0);
        for (int i=0; i<m; ++i)
        {
            res[i] = std::accumulate(matrix[i].begin(), matrix[i].end(), 0);
        }
        return res;
    }
};