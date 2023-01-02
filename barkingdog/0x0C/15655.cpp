#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int arr2[10];
bool isused[10];

void func(int k, int cur)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
      cout << arr2[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (!isused[i] && cur < arr[i])
    {
      arr2[k] = arr[i];
      isused[i] = 1;
      func(k + 1, arr[i]);
      isused[i] = 0;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  func(0, 0);
}