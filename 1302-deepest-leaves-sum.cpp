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
  int deepestLeavesSum(TreeNode *root)
  {
    int result = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      result = 0;
      int n = q.size();

      for (int i = 0; i < n; i++)
      {
        TreeNode *x = q.front();
        if (x->left)
          q.push(x->left);
        if (x->right)
          q.push(x->right);

        result += x->val;
        q.pop();
      }
    }

    return result;
  }
};