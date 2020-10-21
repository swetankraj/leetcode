class Solution
{
public:
  int numIdenticalPairs(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    int result = 0;

    for (int x : nums)
      mp[x]++;
    for (auto y : mp)
    {
      int n = y.second;
      if (n == 1)
        continue;
      else
        result += n * (n - 1) / 2;
    }

    return result;
  }
};