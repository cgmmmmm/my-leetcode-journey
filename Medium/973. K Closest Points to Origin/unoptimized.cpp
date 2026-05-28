class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k == points.size()) return points;

        std::map<int, std::vector<int>> distancesToCoordinatesIndices;
        for (int i=0; i<points.size(); ++i)
        {
            int distance = std::pow(points[i][0], 2) + std::pow(points[i][1], 2);
            distancesToCoordinatesIndices[distance].push_back(i);
        }
        
        std::vector<vector<int>> res(k, std::vector<int>(2, 0));
        int resIdx = 0;
        for (const auto& [distance, coordinateIndices] : distancesToCoordinatesIndices)
        {
            for (int idx : coordinateIndices)
            {
                if (resIdx == k) break;
                res[resIdx] = points[idx];
                resIdx++;
            }
        }

        return res;
    }
};