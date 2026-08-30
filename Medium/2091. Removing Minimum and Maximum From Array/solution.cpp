class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();
        
        int minv = INT_MAX;
        int maxv = INT_MIN;
        int mini = 0;
        int maxi = 0;
        
        for (int i=0; i<n; ++i)
        {
            if (nums[i] > maxv)
            {
                maxv = nums[i];
                maxi = i;
            }
            if (nums[i] < minv)
            {
                minv = nums[i];
                mini = i;
            }
        }

        int idxmx = std::max(maxi, mini);
        int idxmn = std::min(maxi, mini);

        int delFront = idxmx + 1;
        int delBack = n - idxmn;
        int delSides = (idxmn+1) + (n-idxmx);

        return std::min({delFront, delBack, delSides});
    }
};