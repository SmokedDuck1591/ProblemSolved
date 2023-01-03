#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int num[10];

void func(int k, int cur)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int tmp = 0;
  for (int i = cur; i < n; i++)
  {
    if (tmp != num[i])
    {
      arr[k] = num[i];
      tmp = arr[k];
      func(k + 1, i + 1);
    }
  }
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  sort(num, num + n);
  func(0, 0);
}