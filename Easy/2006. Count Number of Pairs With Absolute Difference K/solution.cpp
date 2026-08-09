class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> mp; // complement : freq
        
        int res = 0;
        for (int num : nums)
        {
            if (mp.count(num)) res += mp[num];
            mp[num+k]++;
            mp[num-k]++;
        }

        return res;
    }
};