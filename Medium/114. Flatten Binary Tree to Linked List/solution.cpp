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
    std::stack<TreeNode*> s;

    void flatten(TreeNode* root) 
    {
        if (root == nullptr) return;

        TreeNode* originalLeft = root->left;
        TreeNode* originalRight = root->right;

        flatten(root->left);
        flatten(root->right);

        if (originalLeft != nullptr)
        {
            TreeNode* tail = originalLeft;
            while (tail->right != nullptr)
            {
                tail = tail->right;
            }

            tail->right = originalRight;
            root->right = originalLeft;
        }

        root->left = nullptr;
    }
};