#include <bits/stdc++.h>
using namespace std;
int arr1[1000002];
int arr2[1000002];
int arr3[2000004];
int n, m;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  for (int i = 0; i < m; i++)
    cin >> arr2[i];
  int nidx = 0;
  int midx = 0;
  for (int i = 0; i < n + m; i++)
  {
    if (nidx == n)
      arr3[i] = arr2[midx++];
    else if (midx == m)
      arr3[i] = arr1[nidx++];
    else if (arr1[nidx] <= arr2[midx])
      arr3[i] = arr1[nidx++];
    else
      arr3[i] = arr2[midx++];
  }
}