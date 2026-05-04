class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 90deg rotation can be achieved by transposing and reversing the matrix
        // transpose: [[0,1], [2,3]] -> [[0,2], [1,3]]
        // reverse: [[0,2], [1,3]] -> [[2,0], [3,1]]

        int n = matrix.size();
        // 1. transpose, diagonal stays the same, swap non-diagonals
        for (int i=0; i<n; ++i)
        {
            for (int j=i; j<n; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. reverse
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n/2; ++j)
            {
                std::swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};
