class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<int> v = nums;
        std::sort(v.begin(), v.end());
        std::unordered_map<int, int> mp;
        for (int i=0; i<n; ++i)
            if (!mp.count(v[i])) mp[v[i]] = i;

        std::vector<int> res(n, 0);
        for (int i=0; i<n; ++i)
        {
            res[i] = mp[nums[i]];
        }

        return res;
    }
};