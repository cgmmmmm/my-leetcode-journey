class Solution {
public:
    int gcd(int a, int b)
    {
       while (b != 0)
       {
           int rem = a % b;
           a = b;
           b = rem;
       }
       return a;
    }
    
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int num : nums)
        {
            if (num > mx) mx = num;
            if (num < mn) mn = num;
        }
        return gcd(mx, mn);
    }
};