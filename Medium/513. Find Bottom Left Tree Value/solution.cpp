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
    int maxDepth = -1;

public:
    void helper(TreeNode* curr, int depth)
    {
        if (curr == nullptr) return;

        helper(curr->left, depth+1);
        if (depth > maxDepth)
        {
            res = curr->val;
            maxDepth = depth;
        }
        helper(curr->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) 
    {
        helper(root, 0);
        return res;
    }
};
