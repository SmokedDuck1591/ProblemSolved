#include <bits/stdc++.h>
using namespace std;
int pre[5002];
int nxt[5002];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k, len;
  vector<int> v;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    pre[i] = (i == 1) ? n : i - 1;
    nxt[i] = (i == n) ? 1 : i + 1;
  }
  int i = 1;

  // 내일 다시 해보기
}