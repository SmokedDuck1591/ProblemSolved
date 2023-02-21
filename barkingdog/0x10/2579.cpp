#include <bits/stdc++.h>
using namespace std;
int stair[300];
int arr[300][2];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> stair[i];

  arr[1][1] = stair[1];
  arr[2][1] = stair[2];
  arr[2][2] = stair[1] + stair[2];

  for (int i = 3; i <= n; i++)
  {
    arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + stair[i];
    arr[i][2] = arr[i - 1][1] + stair[i];
  }

  cout << max(arr[n][1], arr[n][2]);
}
