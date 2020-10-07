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

public:
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    TreeNode *value = new TreeNode(val);

    if (root == nullptr)
      return value;

    if (val < root->val && root->left == nullptr)
    {
      root->left = value;
      return root;
    }
    else if (val > root->val && root->right == nullptr)
    {
      root->right = value;
      return root;
    }

    val < root->val ? insertIntoBST(root->left, val) : insertIntoBST(root->right, val);

    return root;
  }
};