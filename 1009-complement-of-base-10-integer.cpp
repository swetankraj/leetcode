class Solution
{
public:
  int bitwiseComplement(int N)
  {
    if (!N)
      return 1;
    int ans = 0, k = 1;
    while (N)
    {
      ans += (((N & 1) ^ 1) * k);
      k <<= 1;
      N >>= 1;
    }

    return ans;
  }
};

//Solution 2
class Solution
{
public:
  int bitwiseComplement(int N)
  {
    if (!N)
      return 1;
    int bits = floor(log2(N) + 1), ans = 0, k = 0;
    N = ~N;
    while (bits)
    {
      int y = pow(2, k);
      ans += (N & y);

      k++;
      bits--;
    }

    return ans;
  }
};