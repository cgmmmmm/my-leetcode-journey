class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        std::unordered_map<int, int> mp;
        for (int i=1; i<=n; ++i)
        {
            actualSum += nums[i-1];
            mp[i] = 0;
        }

        int dup = -1;
        for (int num : nums)
        {
            mp[num]++;
            if (mp[num] == 2) dup = num;
        }

        return {dup, expectedSum - actualSum + dup};
    }
};