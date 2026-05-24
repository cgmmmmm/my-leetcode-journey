class Solution {
public:
    int minimumSwaps(vector<int>& nums) 
    {
        int totalZeros = 0;
        for (int n : nums)
        {
            if (n == 0) totalZeros++;
        }

        int start = nums.size() - totalZeros; // zeros ending should start here
        int res = 0;
        for (int i=start; i<nums.size(); ++i)
        {
            if (nums[i] != 0) res++;
        }

        return res;
    }
};