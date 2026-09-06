class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2){
            return p1[1] < p2[1];
        });

        int res = 0;
        int curr = INT_MIN;
        for (const auto& p : pairs)
        {
            if (p[0] > curr)
            {
                curr = p[1];
                res++;
            }
        }

        return res;
    }
};