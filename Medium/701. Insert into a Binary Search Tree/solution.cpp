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
    void helper(TreeNode* curr, int val, bool& inserted)
    {
        if (inserted) return;
        if (curr == nullptr) 
        {
            return;
        }

        if (val > curr->val)
        {
            helper(curr->right, val, inserted);
            if (!inserted)
            {
                curr->right = new TreeNode(val);
                inserted = true;
            }
        }
        else
        {
            helper(curr->left, val, inserted);
            if (!inserted)
            {
                curr->left = new TreeNode(val);
                inserted = true;
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if (!root) return new TreeNode(val);
        
        bool inserted = false;
        helper(root, val, inserted);
        return root;
    }
};
