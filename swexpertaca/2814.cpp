#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int graph[11][11];

int main(void)
{
  int test_case;
  int T;

  cin >> test_case;

  for (int i = 1; i <= test_case; i++)
  {
    int n, m;
    cin >> n >> m;
    for (int j = 0; j < m; j++)
    {
      int x, y;
      cin >> x >> y;
      graph[x][y] = graph[y][x] = 1;
        }
  }
}