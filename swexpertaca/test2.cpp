#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  string n, tmp;
  int x, y;
  cin >> n >> x >> y;
  deque<int> dq;

  for (int i = 0; i < n.length(); i++)
  {
    if (n[i] > x and n[i] < y)
    {
      dq.push_front(x);
    }
    if (n[i] > y)
      dq.push_front(y);
    if (n[i] < x)
      dq.pop_front();
  }
}