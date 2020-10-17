class Solution
{
public:
  vector<string> findRepeatedDnaSequences(string s)
  {
    if (s.length() < 10)
      return {};

    unordered_map<string, int> mp;
    vector<string> result;
    for (int i = 0; i <= s.length() - 10; i++)
    {
      string sub = s.substr(i, 10);
      if (!mp[sub])
        mp[sub]++;
      else if (mp[sub] == 1)
      {
        result.push_back(sub);
        mp[sub]++;
      }
    }
    return result;
  }
};