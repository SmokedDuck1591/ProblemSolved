#include <bits/stdc++.h>
using namespace std;
int n, x, tmp;

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> x;

  while (--n)
  {
    cin >> tmp;
    if (tmp < x)
      cout << tmp << ' ';
  }
}