class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {   
        std::unordered_map<int, int> freq;
        int res=0;
        int l=0;
        for (int r=0; r<nums.size(); ++r)
        {
            freq[nums[r]]++;
            
            while (freq[nums[r]] > k)
            {
                freq[nums[l]]--;
                l++;
            }

            res = std::max(r-l+1, res);
        }

        return res;
    }
};