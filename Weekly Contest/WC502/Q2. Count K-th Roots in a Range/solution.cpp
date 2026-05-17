class Solution {
public:
    int countPerfPow(int n, int k)
    {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (k == 1) return n+1;

        int root = std::round(std::pow(n, 1.0/k));

        if (std::pow((long long)root, k) > n)
        {
            root--;
        }

        return root+1;
    }
    
    int countKthRoots(int l, int r, int k) {
        // y is perfect kth power if there exist an integer x that y = x^k
        // l and r is the range of nums

        int res = countPerfPow(r, k) - countPerfPow(l-1, k);

        return res;
    }
};©leetcode
