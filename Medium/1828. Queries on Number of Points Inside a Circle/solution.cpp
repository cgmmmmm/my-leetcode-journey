class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
        const size_t n = queries.size();

        std::vector<int> res(n, 0);
        for (size_t i=0; i<n; ++i)
        {
            const auto& q = queries[i];
            long long r_squared = 1LL * q[2] * q[2];
            for (const auto& point : points)
            {
                long long dist_x = point[0] - q[0];
                long long dist_y = point[1] - q[1];
                if (dist_x*dist_x + dist_y*dist_y <= r_squared) ++res[i];
            }
        }

        return res;
    }
};