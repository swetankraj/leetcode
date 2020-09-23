class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int r = obstacleGrid.size(), c = obstacleGrid[0].size();
    int dp[r][c];
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
        dp[i][j] = 1;
    }

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (i == 0 && j == 0)
        {
          if (!obstacleGrid[i][j])
            dp[i][j] = 1;
          else
            dp[i][j] = 0;
        }
        else if (i == 0)
        {
          if (!obstacleGrid[i][j])
            dp[i][j] = dp[i][j - 1];
          else
            dp[i][j] = 0;
        }
        else if (j == 0)
        {
          if (!obstacleGrid[i][j])
            dp[i][j] = dp[i - 1][j];
          else
            dp[i][j] = 0;
        }
        else
        {
          if (!obstacleGrid[i][j])
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
          else
            dp[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
        cout << dp[i][j] << " ";
      cout << endl;
    }
    return dp[r - 1][c - 1];
  }
};