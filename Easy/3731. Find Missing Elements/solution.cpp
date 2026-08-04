class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int n = nums.size();
        std::vector<int> res;
        for (int i=0; i<n-1; ++i)
        {
            int x = nums[i];
            while (x < nums[i+1]-1)
            {
                x++;
                res.push_back(x);
            }
        }
        
        return res;
    }
};