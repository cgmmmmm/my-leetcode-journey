class Solution {
public:
    bool check(vector<int>& nums) {
        // in a rotated or non-rotated sorted array, the drop is at most ONCE
        // just need to find the number of drops, if drops > 1, its false

        int drops = 0;
        int n = nums.size();
        for (int i=0; i<n; ++i)
        {
            if (nums[i] > nums[(i+1) % n]) drops++;
        }

        return drops <= 1;
    }
};