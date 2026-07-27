class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int a=INT_MIN, b=INT_MIN;
        for (int num : nums)
        {
            if (num >= a)
            {
                b = a;
                a = num;
            }
            else if (num >= b)
            {
                b = num;
            }
        }

        return (a-1)*(b-1);
    }
};