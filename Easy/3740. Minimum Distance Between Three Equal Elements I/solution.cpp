class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> appearance;

        for (int i=0; i<nums.size(); i++)
        {
            appearance[nums[i]].push_back(i);
        }

        const int INF = std::numeric_limits<int>::max();
        int res = INF;
        for (const auto& pair : appearance)
        {
            if (pair.second.size() >= 3)
            {
                for (int idx=0; idx<pair.second.size()-2; idx++)
                {
                    res = std::min(res, 2 * (pair.second[idx+2] - pair.second[idx]));
                }
            }
        }

        return (res == INF) ? -1 : res;
    }
};
