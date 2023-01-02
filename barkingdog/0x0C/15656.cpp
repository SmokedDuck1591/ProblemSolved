#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int arr2[10];

void func(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << arr2[arr[i]] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++)
  {
    arr[k] = i;
    func(k + 1);
  }
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> arr2[i];
  sort(arr2, arr2 + n);
  func(0);
}