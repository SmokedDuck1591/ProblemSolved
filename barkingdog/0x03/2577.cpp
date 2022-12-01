#include <bits/stdc++.h>
using namespace std;
int cnt[10];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int a, b, c, num;
  cin >> a >> b >> c;
  num = a * b * c;

  while (num != 0)
  {
    cnt[num % 10]++;
    num /= 10;
  }

  for (auto c : cnt)
    cout << c << '\n';
}