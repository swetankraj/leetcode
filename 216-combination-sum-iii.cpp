class Solution
{
    vector<vector<int>> ans;

    void solve(int x, int k, int n, vector<int> &temp)
    {
        if (temp.size() == k && n == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = x; i <= 9; i++)
        {
            temp.push_back(i);
            solve(i + 1, k, n - i, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        solve(1, k, n, temp);
        return ans;
    }
};