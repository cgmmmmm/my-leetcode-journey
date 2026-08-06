class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        int p = 1;
        int x = n;
        while (x != 0)
        {
            p *= (x % 10);
            x /= 10;
        }
        while (p % t != 0)
        {
            n++;
            p = 1;
            x = n;
            while (x != 0)
            {
                p *= (x % 10);
                x /= 10;
            }
        }
        return n;
    }
};