#include <bits/stdc++.h>
using namespace std;
int arr[100002];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  int en = 0;
  for (int st = 0; st < n; st++)
  {
    while (en < n && arr[en] - arr[st] < m)
      en++;
    if (en == n)
      break;
    }
}