class Solution {
public:
    bool consecutiveSetBits(int n) {
        int prev = n % 2;
        n /= 2;
        int pairCount = 0;
        while (n > 0)
        {
            int curr = n % 2;
            if (curr == 1 && prev == 1)
            {
                pairCount++;
            }
            prev = curr;
            n /= 2;
        }

        return pairCount == 1;
    }
};©leetcode