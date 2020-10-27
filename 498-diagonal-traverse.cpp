class Solution
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
  {
    if (!matrix.size())
      return {};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> result;

    for (int diagonal = 0; diagonal <= n + m - 1; diagonal++)
    {
      vector<int> temp;
      int r = diagonal < m ? 0 : diagonal - m + 1;
      int c = diagonal < m ? diagonal : m - 1;

      while (r < n && c > -1)
      {
        temp.push_back(matrix[r++][c--]);
      }

      if (diagonal % 2 == 0)
        reverse(temp.begin(), temp.end());

      for (int x : temp)
        result.push_back(x);
    }

    return result;
  }
};