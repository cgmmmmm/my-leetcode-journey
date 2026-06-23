class Solution {
public:
    int climbStairs(int n) {
        // fib seq: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
        int prev = 0;
        int curr = 1;
        int next = 1;
        while (n-- > 0)
        {
            next += prev;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};