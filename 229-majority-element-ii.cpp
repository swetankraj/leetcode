class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int morethan = floor(nums.size() / 3);
    vector<int> result;
    unordered_map<int, int> mp;

    for (auto x : nums)
      mp[x]++;
    for (auto it : mp)
    {
      if (it.second > morethan)
        result.push_back(it.first);
    }

    return result;
  }
};