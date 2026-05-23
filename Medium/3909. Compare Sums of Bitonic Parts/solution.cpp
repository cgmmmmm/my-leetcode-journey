class Solution {
public:
    int compareBitonicSums(vector<int>& nums) 
    {
        long long asc_sum = 0, desc_sum = 0, max_val = 0;
        for (int i=0; i<nums.size()-1; ++i)
        {
            max_val = max_val > nums[i] ? max_val : nums[i];
            if (nums[i] < nums[i+1])
            {
                asc_sum += nums[i];
            }
            else 
            {
                desc_sum += nums[i];
            }
        }
        asc_sum += max_val;
        desc_sum += nums[nums.size()-1];

        if (asc_sum > desc_sum) return 0;
        if (asc_sum < desc_sum) return 1;
        return -1;
    }
};