#include <bits/stdc++.h>
using namespace std;
int arr[1002][3];
int r[1002], g[1002], b[1002];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> r[i] >> g[i] >> b[i];

  arr[1][0] = r[1];
  arr[1][1] = g[1];
  arr[1][2] = b[1];

  for (int i = 2; i <= n; i++)
  {
    arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + r[i];
    arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + g[i];
    arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + b[i];
  }

  cout << *min_element(arr[n], arr[n] + 3);
}