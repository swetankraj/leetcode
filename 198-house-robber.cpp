class Solution
{
    int solve(vector<int> &nums, int n, int dp[])
    {
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = max(nums[n] + solve(nums, n - 2, dp), solve(nums, n - 1, dp));
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int dp[n + 2];
        memset(dp, -1, sizeof(dp));
        return max(solve(nums, n, dp), solve(nums, n, dp));
    }
};