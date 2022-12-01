#include <bits/stdc++.h>
using namespace std;
int a[21];
int b[21][21];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);

  /// 배열 초기화 방법
  fill(a, a + 21, 0); // 1차원
  for (int i = 0; i < 21; i++)
    fill(b[i], b[i] + 21, 0); // 2차원
}
