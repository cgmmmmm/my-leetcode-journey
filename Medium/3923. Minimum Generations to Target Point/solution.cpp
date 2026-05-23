class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) 
    {
        if (std::find(points.begin(), points.end(), target) != points.end()) return 0;
        if (points.size() < 2) return -1;

        std::set<std::vector<int>> seen(points.begin(), points.end());
        int k = 0;
        
        while (true)
        {
            std::set<std::vector<int>> nextGen;
            
            for (auto it1 = seen.begin(); it1 != seen.end(); ++it1)
            {
                for (auto it2 = std::next(it1); it2 != seen.end(); ++it2)
                {
                    int xn = std::floor(((*it1)[0] + (*it2)[0]) / 2.0);
                    int yn = std::floor(((*it1)[1] + (*it2)[1]) / 2.0);
                    int zn = std::floor(((*it1)[2] + (*it2)[2]) / 2.0);
                    std::vector<int> newPoints = {xn, yn, zn};

                    if (newPoints == target) return k+1;
                    if (seen.find(newPoints) == seen.end()) nextGen.insert(newPoints);
                }
            }

            if (nextGen.empty()) return -1;

            seen.insert(nextGen.begin(), nextGen.end());
            k++;
        }
    }
};