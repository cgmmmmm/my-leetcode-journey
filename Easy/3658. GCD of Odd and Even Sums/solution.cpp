class Solution {
public:
    int gcd(int a, int b)
    {
        int rem;
        while (b != 0)
        {
            rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) 
    {
        int oddSum = n * (n + 1);
        int evenSum = n * n;

        return gcd(oddSum, evenSum);
    }
};