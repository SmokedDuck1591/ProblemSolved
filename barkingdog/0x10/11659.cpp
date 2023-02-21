#include <bits/stdc++.h>
using namespace std;
int arr1[100002]; // 수 넣는 곳
int arr2[100002]; // dynamic programming 하는 곳

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr1[i];
    arr2[i] = arr2[i - 1] + arr1[i];
  }

  while (m--)
  {
    int i, j;
    cin >> i >> j;
    cout << arr2[j] - arr2[i - 1] << '\n';
  }
}