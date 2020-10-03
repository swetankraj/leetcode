class Solution
{
  set<vector<int>> result;
  vector<vector<int>> result2;
  int cand_len = 0;

  void solve(vector<int> &candidates, vector<int> inter_vec, int target)
  {
    if (target == 0)
    {
      sort(inter_vec.begin(), inter_vec.end());
      result.insert(inter_vec);
      return;
    }
    if (target < 0)
      return;

    for (int i = 0; i < cand_len; i++)
    {
      vector<int> inter_vec_cpy = inter_vec;
      if (candidates[i] <= target)
      {
        inter_vec_cpy.push_back(candidates[i]);
        // for(auto x: inter_vec_cpy) cout<<x<<(i)<<" ";
        // cout<<target-candidates[i]<<endl;
        solve(candidates, inter_vec_cpy, target - candidates[i]);
      }
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    cand_len = candidates.size();

    for (int i = 0; i < cand_len; i++)
    {
      if (candidates[i] <= target)
      {
        vector<int> inter_vec = {candidates[i]};
        solve(candidates, inter_vec, target - candidates[i]);
      }
    }

    for (auto x : result)
      result2.push_back(x);
    return result2;
  }
};