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
public:
    int res = 0;

    void preOrder(TreeNode* curr, int currSum)
    {
        // root, left, right
        if (!curr) return;

        currSum = (currSum * 10) + curr->val;
        preOrder(curr->left, currSum);
        preOrder(curr->right, currSum);

        if (curr->left == nullptr && curr->right == nullptr) res += currSum;
    }

    int sumNumbers(TreeNode* root) 
    {
        preOrder(root, 0);
        return res;
    }
};