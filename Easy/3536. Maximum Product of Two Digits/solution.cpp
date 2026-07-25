class Solution {
public:
    int maxProduct(int n) 
    {
        int mx1 = -1; // greatest
        int mx2 = -1; // 2nd greatest
        while (n > 0)
        {
            int digit = n % 10;
            if (digit > mx1)
            {
                mx2 = mx1;
                mx1 = digit;
            }
            else
            {
                if (digit > mx2) mx2 = digit;
            }

            n /= 10;
        }

        return mx1 * mx2;
    }
};