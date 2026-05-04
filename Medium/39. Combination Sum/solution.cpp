class Solution {
public:
    void backtrack(
        std::vector<std::vector<int>>& res, 
        std::vector<int>& combinations,
        int it,
        int total,
        const std::vector<int>& candidates, 
        const int target)
    {   
        if (total >= target)
        {
            if (total == target) res.push_back(combinations);
            return;
        }

        for (int i = it; i<candidates.size(); ++i)
        {
            combinations.push_back(candidates[i]);
            total += candidates[i];
            backtrack(res, combinations, i, total, candidates, target);
            if (!combinations.empty()) 
            {
                total -= combinations.back();
                combinations.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if (candidates.size() == 0) return {};

        std::vector<std::vector<int>> res;
        std::vector<int> combinations;
        int it = 0;
        int total = 0;

        backtrack(res, combinations, it, total, candidates, target);
    
        return res;
    }
};
