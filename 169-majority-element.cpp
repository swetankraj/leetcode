class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int morethan = floor(nums.size() / 2);
    unordered_map<int, int> mp;

    for (auto x : nums)
      mp[x]++;
    for (auto it : mp)
      if (it.second > morethan)
        return it.first;
    return 0;
  }
};