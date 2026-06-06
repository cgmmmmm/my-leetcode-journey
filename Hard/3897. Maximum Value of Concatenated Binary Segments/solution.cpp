using ll = long long;

class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) 
    {
        int n = nums1.size();

        std::vector<std::pair<int, int>> pairs(n);
        for (int i=0; i<n; ++i)
        {
            pairs[i] = {nums1[i], nums0[i]};
        }

        // sort the segment first,
        // prioritize segments that contains zero '0's over those that have '0's
        // tiebreaker:
        // followed by prioritizing segments with a greater count of '1's
        // followed by prioritizing segments with a lesser count of '0's
        std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            bool a_has_no_zeros = (a.second == 0);
            bool b_has_no_zeros = (b.second == 0);

            if (a_has_no_zeros != b_has_no_zeros) {
                return a_has_no_zeros; 
            }

            if (a.first != b.first) {
                return a.first > b.first; 
            }

            return a.second < b.second;
        });

        ll val = 0;
        const ll MOD = 1'000'000'007;
        for (const auto& [ones, zeros] : pairs)
        {
            for (int i=0; i<ones; ++i)
            {
                val = (val * 2 + 1) % MOD;
            }
            for (int i=0; i<zeros; ++i)
            {
                val = (val * 2 + 0) % MOD;
            }
        }
        
        return val;
    }
};