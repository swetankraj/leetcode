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
class Solution
{
    int solve(TreeNode *root, int ans)
    {
        if (!root)
            return 0;

        ans <<= 1;
        if (root->val == 1)
            ans += 1;
        if (!root->left && !root->right)
            return ans;
        return solve(root->left, ans) + solve(root->right, ans);
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        return solve(root, 0);
    }
};