class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();

        for (int i=0; i<n; ++i)
        {
            int ix = std::abs(nums[i]) - 1;
            if (nums[ix] > 0) nums[ix] *= -1;
        }

        std::vector<int> res;
        for (int i=0; i<n; ++i)
        {
            if (nums[i] > 0) res.push_back(i + 1);
        }

        return res;
    }
};