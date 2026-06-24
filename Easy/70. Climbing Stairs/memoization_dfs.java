class Solution {
    int explorePaths(int[] memo, int curr_step, int n)
    {
        if (curr_step > n) return 0;

        if (curr_step == n) return 1;

        if (memo[curr_step] != -1) return memo[curr_step];

        int one_step = explorePaths(memo, curr_step + 1, n);
        int two_steps = explorePaths(memo, curr_step + 2, n);

        memo[curr_step] = one_step + two_steps;
        return memo[curr_step];
    }

    public int climbStairs(int n) {
        int[] memo = new int[n+1];
        Arrays.fill(memo, -1);

        return explorePaths(memo, 0, n);

        // int prev = 0;
        // int curr = 1;
        // int next = 1;
        // while (n-- > 0)
        // {
        //     next += prev;
        //     prev = curr;
        //     curr = next;
        // }

        // return curr;
    }
}