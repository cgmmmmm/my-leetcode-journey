class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) 
    {
        int res = 0;
        for (const int num : nums)
        {
            int x = num;
            while (x > 0)
            {
                if (x % 10 == digit) res++;
                x /= 10; 
            }
        }
        return res;
    }
};
