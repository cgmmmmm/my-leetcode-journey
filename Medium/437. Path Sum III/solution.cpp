/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res = 0;

public:
    void dfs(TreeNode* curr, std::unordered_map<long, int>& psMap, long prefixSum, const int targetSum)
    {
        if (curr == nullptr) return;
        prefixSum += curr->val;
        if (psMap.count(prefixSum - targetSum)) res += psMap[prefixSum - targetSum];
        psMap[prefixSum]++;

        dfs(curr->left, psMap, prefixSum, targetSum);
        dfs(curr->right, psMap, prefixSum, targetSum);

        psMap[prefixSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<long, int> psMap;
        psMap[0] = 1;
        dfs(root, psMap, 0, targetSum);
        
        return res;
    }
};