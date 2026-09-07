class Solution {
public:
    std::vector<std::vector<int>> res;

    void backtrack(int idx, std::vector<int>& sseq, const int n, const std::vector<int>& nums)
    {
        // inorder
        if (sseq.size() >= 2)
        {
            res.push_back(sseq);
        }

        std::unordered_set<int> level_st;

        for (int i=idx; i<n; ++i)
        {
            if (!sseq.empty() && nums[i] < sseq.back() || level_st.count(nums[i]))
            {
                continue;
            }
            level_st.insert(nums[i]);
            sseq.push_back(nums[i]);
            backtrack(i+1, sseq, n, nums);
            sseq.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        std::vector<int> sseq;
        const int n = nums.size();
        backtrack(0, sseq, n, nums);
        return res;
    }
};