#include <bits/stdc++.h>
using namespace std;
long long dp[105];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  dp[1] = 1LL;
  dp[2] = 1LL;
  dp[3] = 1LL;

  for (int i = 4; i <= 100; i++)
    dp[i] = dp[i - 3] + dp[i - 2];

  while (n--)
  {
    int tmp;
    cin >> tmp;

    cout << dp[tmp] << '\n';
  }
}