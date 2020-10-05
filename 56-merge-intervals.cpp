class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;

    // for(auto x: intervals){
    //     cout<<x[0]<<" "<<x[1]<<endl;
    // }

    for (auto x : intervals)
    {
      if (result.size() == 0)
        result.push_back(x);
      else
      {
        bool found = false;
        for (int i = 0; i < result.size(); i++)
        {
          if (x[0] <= result[i][1])
          {
            result[i][0] = min(result[i][0], x[0]);
            result[i][1] = max(result[i][1], x[1]);
            found = true;
            break;
          }
        }
        if (!found)
          result.push_back(x);
      }
    }

    return result;
  }
};