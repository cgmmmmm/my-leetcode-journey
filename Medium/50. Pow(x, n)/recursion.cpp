class Solution {
public:
    double myPow(double x, int n) 
    {
        if (n == 0) return 1.0;
        
        double res = myPow(x, n/2);
        res *= res;

        if (n % 2)
        {
            if (n > 0) res *= x;
            else res /= x;
        }

        return res;
    }
};
