#include <bits/stdc++.h>
using namespace std;
queue<int> Q;

void shuffle()
{
  int tmp;
  Q.pop();
  tmp = Q.front();
  Q.pop();
  Q.push(tmp);
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    Q.push(i);

  while (Q.size() != 1)
    shuffle();

  cout << Q.front();
}
