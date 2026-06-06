class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftSum(n, 0);
        std::vector<int> rightSum(n, 0);
        int l = 0, r = n-1;
        int lsum = 0, rsum = 0;
        while (l<n)
        {
            leftSum[l] = lsum;
            rightSum[r] = rsum;
            lsum += nums[l];
            rsum += nums[r];
            l++;
            r--;
        }
        
        std::vector<int> ans;
        ans.reserve(nums.size());
        for (int i=0; i<n; ++i)
        {
            ans.push_back(std::abs(rightSum[i] - leftSum[i]));
        }
        
        return ans;
    }
};