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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<int, TreeNode*> mp;
        std::unordered_set<int> childNodes;

        for (std::vector<int>& desc : descriptions)
        {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (mp.find(parent) == mp.end()) mp[parent] = new TreeNode(parent);
            if (mp.find(child) == mp.end()) mp[child] = new TreeNode(child);

            if (isLeft == 1) mp[parent]->left = mp[child];
            else mp[parent]->right = mp[child];

            childNodes.insert(child);
        }

        for (const auto& [val, node] : mp)
        {
            if (childNodes.find(val) == childNodes.end()) return node;
        }

        return nullptr;
    }
};