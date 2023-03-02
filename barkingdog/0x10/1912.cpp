#include <bits/stdc++.h>
using namespace std;
int dp[100002];
int arr[100002];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    dp[i] = arr[i];
  }
  for (int i = 1; i <= n; i++)
    dp[i] = max(dp[i], dp[i - 1] + arr[i]);

  cout << *max_element(dp + 1, dp + n + 1);
}