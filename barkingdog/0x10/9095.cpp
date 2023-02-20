#include <bits/stdc++.h>
using namespace std;
int arr[12];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    for (int i = 4; i <= n; i++)
      arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

    cout << arr[n] << '\n';
  }
}