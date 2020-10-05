class Solution
{
  bool static custom_compare(vector<int> v1, vector<int> v2)
  {
    if (v1[0] < v2[0])
      return true;
    else if (v1[0] == v2[0] && v1[1] > v2[1])
      return true;
    return false;
  }

public:
  int removeCoveredIntervals(vector<vector<int>> &intervals)
  {
    int mini = INT_MAX, maxm = INT_MIN, ans = 0;
    sort(intervals.begin(), intervals.end(), custom_compare);

    // for(auto x: intervals){
    //     cout<<x[0]<<" "<<x[1]<<endl;
    // }

    for (auto x : intervals)
    {
      if (x[0] < mini || x[1] > maxm)
      {
        mini = min(x[0], mini);
        maxm = max(x[1], maxm);
        ans++;

        cout << mini << " " << maxm << endl;
      }
    }

    return ans;
  }
};