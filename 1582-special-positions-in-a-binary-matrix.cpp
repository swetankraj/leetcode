class Solution
{
public:
    bool checkit(vector<vector<int>> &mat, int i, int j, int row, int col)
    {
        for (int x = 0; x < col; x++)
        {
            if (x == j)
                continue;
            if (mat[i][x] == 1)
                return true;
        }

        for (int y = 0; y < row; y++)
        {
            if (y == i)
                continue;
            if (mat[y][j] == 1)
                return true;
        }

        return false;
    }
    int numSpecial(vector<vector<int>> &mat)
    {
        int row = mat.size(), col = mat[0].size(), ans = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (!checkit(mat, i, j, row, col))
                        ans++;
                }
            }
        }

        return ans;
    }
};