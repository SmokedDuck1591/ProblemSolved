#include <bits/stdc++.h>
using namespace std;
long long dp[102][10];
int n;
long long ans;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;

  for (int i = 1; i <= 9; i++)
    dp[1][i] = 1;

  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (j == 0)
        dp[i][j] = dp[i - 1][j + 1];
      else if (j == 9)
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
    }
  }
  for (int i = 0; i <= 9; i++)
    ans += dp[n][i];

  cout << ans % 1000000000;
}