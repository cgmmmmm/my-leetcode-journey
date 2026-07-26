class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a=INT_MIN, b=INT_MIN, c=INT_MIN;
        int d=INT_MAX, e=INT_MAX;
        for (int num : nums)
        {
            if (num >= a)
            {
                c = b;
                b = a;
                a = num;
            }
            else if (num >= b)
            {
                c = b;
                b = num;
            }
            else if (num >= c)
            {
                c = num;
            }

            if (num <= d)
            {
                e = d;
                d = num;
            }
            else if (num <= e)
            {
                e = num;
            }
        }
        
        return std::max(a*b*c, d*e*a);
    }
};