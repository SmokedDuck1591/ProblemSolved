#include <bits/stdc++.h>
using namespace std;
long long arr[100002];

long long mxnum;
int mxcnt(1), cnt(1);

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);
  mxnum = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i - 1] == arr[i])
      cnt++;
    else
    {
      if (mxcnt < cnt)
      {
        mxcnt = cnt;
        mxnum = arr[i - 1];
      }
      cnt = 1;
    }
  }
  if (cnt > mxcnt)
    mxnum = arr[n - 1];
  cout << mxnum;
}