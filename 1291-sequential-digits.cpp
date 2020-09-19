class Solution
{
    vector<int> result;
    void solve(int x, int i, int low, int high)
    {
        if (x > high || i > 9)
            return;
        if (x >= low && x <= high)
            result.push_back(x);
        solve((x * 10) + (i + 1), i + 1, low, high);
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        for (int i = 1; i <= 9; i++)
        {
            int x = i;
            solve(x, x, low, high);
        }
        sort(result.begin(), result.end());
        return result;
    }
};