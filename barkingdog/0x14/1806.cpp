#include <bits/stdc++.h>
using namespace std;
int arr[100002];
int mn = 0x7fffffff;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, s;
  cin >> n >> s;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int en = 0;
  int tot = arr[0];

  for (int st = 0; st < n; st++)
  {
    while (tot < s && en != n)
    {
      en++;
      tot += arr[en];
    }
    if (en == n)
      break;
    mn = min(mn, en - st + 1);
    tot -= arr[st];
  }

  if (mn == 0x7fffffff)
    mn = 0;
  cout << mn;
}