#include <bits/stdc++.h>
using namespace std;
int arr[100002];
int arr2[2000002];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, ans(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    arr[i] = tmp;
    arr2[tmp] = 1;
  }
  cin >> m;

  for (int i = 0; i < n; i++)
  {
    if (m - arr[i] > 0 && arr2[m - arr[i]])
      ans++;
  }
  cout << ans / 2;
}
