class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        if (k == n) return points;

        struct PointsDistances
        {
            int distance;
            int pointsIndex;
            bool operator<(const PointsDistances& other) const
            {
                return distance < other.distance;
            }
        };

        std::vector<PointsDistances> distances(n);
        for (int i=0; i<points.size(); ++i)
        {
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distances[i] = {distance, i};
        }

        // void nth_element(start, nth, end), arranges elements in place, arranges only the element that would be at the "nth" index after sorting either ascending or ddescending
        std::nth_element(distances.begin(), distances.begin() + k, distances.end());
        
        std::vector<std::vector<int>> res;
        res.reserve(k);
        for (int i=0; i<k; ++i)
        {
            res.push_back(std::move(points[distances[i].pointsIndex]));
        }
        
        return res;
    }
};