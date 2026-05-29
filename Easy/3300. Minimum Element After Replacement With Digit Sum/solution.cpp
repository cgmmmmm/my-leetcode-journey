class Solution {
public:
    int minElement(vector<int>& nums) 
    {
        int res = std::numeric_limits<int>::max();
        for (int num : nums)
        {
            int curr = 0;
            while (num > 0)
            {
                curr += (num % 10);
                num /= 10;
            }
            res = (res > curr) ? curr : res;
        }
        return res;
    }
};