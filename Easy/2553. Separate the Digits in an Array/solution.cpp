class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        std::vector<int> res;

        for (int i=nums.size()-1; i>=0; i--)
        {
            int n = nums[i];
            while (n > 0)
            {
                res.push_back(n % 10);
                n /= 10;
            }
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};
