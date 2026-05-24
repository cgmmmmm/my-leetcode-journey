class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) 
    {
        vector<int> ans;
        int prev = nums[0];
        int count = 0;
        for (int n : nums)
        {
            if (prev == n && count == k)
            {
                continue;
            }
            if (prev != n) count = 0;
            ans.push_back(n);
            count++;
            prev = n;
        }

        return ans;
    }
};