class Solution {
public:
    int pivotInteger(int n) {
        if (n==1) return 1;
        if (n<=7) return -1;

        int x = n;
        int sum = n*(n+1)/2;
        int xSum = n;
        while (x > 1)
        {
            if (xSum == sum) return x;
            sum -= x;
            xSum += --x;
        }
        return -1;
    }
};