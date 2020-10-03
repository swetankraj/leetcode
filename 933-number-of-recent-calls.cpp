class RecentCounter
{
  queue<long long> q;

public:
  RecentCounter()
  {
  }

  int ping(int t)
  {
    q.push(t);

    long long x = q.front();
    while (q.front() < t - 3000)
      q.pop();

    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */