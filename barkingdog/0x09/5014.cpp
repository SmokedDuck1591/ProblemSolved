#include <bits/stdc++.h>
using namespace std;
int f, s, g;
int building[1000005];
int dx[2]; // u, d
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> f >> s >> g >> dx[0] >> dx[1];
  fill(building + 1, building + f + 1, -1);
  queue<int> Q;
  Q.push(s);
  building[s] = 0;

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 2; dir++)
    {
      int nx = cur + dx[dir];
      if (nx > f || nx <= 0 || building[nx] != -1)
        continue;
      building[nx] = building[cur] + 1;
      Q.push(nx);
    }
  }
  if (building[g] == -1)
    cout << "use the stairs";
  else
    cout << building[g];
}