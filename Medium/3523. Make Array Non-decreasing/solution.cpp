class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) 
    {
        int res = 1;
        int curr = nums[0];
        for (int i=1; i<nums.size(); ++i)
        {
            if (curr > nums[i])
                continue;
            curr = nums[i];
            res++;
        }
        return res;
    }
};