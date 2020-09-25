class NumArray
{
  int st[100005], n = 0;
  vector<int> arr;

  void build(int idx, int low, int high, vector<int> &nums)
  {
    arr = nums;
    if (low == high)
    {
      st[idx] = nums[low];
      return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid, nums);
    build(2 * idx + 2, mid + 1, high, nums);
    st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
  }

  int query(int idx, int low, int high, int l, int r)
  {
    if (low >= l && high <= r)
    {
      return st[idx];
    }
    if (high < l || low > r)
      return 0;
    int mid = (low + high) / 2;
    long long left = query(2 * idx + 1, low, mid, l, r);
    long long right = query(2 * idx + 2, mid + 1, high, l, r);
    return left + right;
  }

  void updateVal(int idx, int low, int high, int i, int diff)
  {
    if (i < low || i > high)
      return;
    st[idx] += diff;

    if (low != high)
    {
      int mid = (low + high) / 2;
      updateVal(2 * idx + 1, low, mid, i, diff);
      updateVal(2 * idx + 2, mid + 1, high, i, diff);
    }
  }

public:
  NumArray(vector<int> &nums)
  {
    n = nums.size() - 1;
    if (n >= 0)
      build(0, 0, n, nums);
  }

  void update(int i, int val)
  {
    int diff = val - arr[i];
    arr[i] = val;
    updateVal(0, 0, n, i, diff);
  }

  int sumRange(int i, int j)
  {
    if (!arr.size())
      return 0;
    int ans = query(0, 0, n, i, j);
    return ans;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */