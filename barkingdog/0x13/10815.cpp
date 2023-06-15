#include <bits/stdc++.h>
using namespace std;
int arr1[500002];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  sort(arr1, arr1 + n);
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int tmp;
    cin >> tmp;

    cout << binary_search(arr1, arr1 + n, tmp) << ' ';
  }
}