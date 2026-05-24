class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        if (n <= 1) return 0;

        auto it = find(nums.begin(), nums.end(), 0);
        int idx = distance(nums.begin(), it);

        int min_ops = INT_MAX;

        int cyc = (n - idx) % n;
        bool is_type_a = true;
        for (int i=0; i<n; ++i)
        {
            if (nums[i] != (i + cyc) % n)
            {
                is_type_a = false;
                break;
            }
        }
        if (is_type_a) min_ops = min({min_ops, idx, n - idx + 2});

        int cyc_rev = n - 1 - idx;
        bool is_type_b = true;
        for (int i=0; i<n; ++i)
        {
            if (nums[i] != n - 1 - ((i + cyc_rev) % n))
            {
                is_type_b = false;
                break;
            }
        }
        if (is_type_b) min_ops = min({min_ops, 1 + cyc_rev, n - cyc_rev + 1});

        return (min_ops == INT_MAX) ? -1 : min_ops;
    }
};