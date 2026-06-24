class Solution {
public:
    int explorePaths(std::vector<int>& memo, int curr_step, const int n)
    {
        if (curr_step > n) return 0;

        if (curr_step == n) return 1;

        if (memo[curr_step] != -1) return memo[curr_step];

        int one_step = explorePaths(memo, curr_step + 1, n);
        int two_steps = explorePaths(memo, curr_step + 2, n);

        memo[curr_step] = one_step + two_steps;
        return memo[curr_step];
    }
    
    int climbStairs(int n) {
        // a naive approach of dfs to compute all the ways to climb n stairs is O(2^N) time
        // we can optimize the time complexity by using precomputed results, this would be O(N) time
        std::vector<int> memo(n+1, -1);

        return explorePaths(memo, 0, n);



        // // fib seq: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
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
};