#include <bits/stdc++.h>
using namespace std;
int n, s, ans;
int m = 2;
int arr[22];
bool isused[22];
void func(int k, int sum, int cur)
{
  if (k == m)
  {
    if (sum == s)
      ans++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (!isused[i] && cur <= i)
    {
      isused[i] = 1;
      func(k + 1, sum + arr[i], i);
      isused[i] = 0;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (arr[i] == s)
      ans++;
  }
  for (int i = 2; i <= n; i++)
  {
    func(0, 0, 0);
    m++;
  }
  cout << ans;
}