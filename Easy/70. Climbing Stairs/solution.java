class Solution {
    public int climbStairs(int n) {
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
}