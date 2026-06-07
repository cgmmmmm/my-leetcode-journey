class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int compatibleSum = 0;
        int start = std::max(n-k, 1);
        for (int x=start; x<=n+k; ++x)
        {
            if ((n & x) == 0) compatibleSum += x;
        }

        return compatibleSum;
    }
};