#include <bits/stdc++.h>
using namespace std;
string board[7];
bool isused[7][7];
int ans;
vector<string> v;
stack<char> st;
void search(int x, int y, int cur, int som)
{
  if (cur == 7)
  {
    if (som > 3)
    {
      string tmp;

      while (!st.empty())
      {
        tmp += st.top();
        st.pop();
      }
        }
    ans++;
    return;
  }
  if (x < 0 || y < 0 || x >= 5 || y >= 5)
    return;
  if (isused[x][y] == 1)
    return;
  st.push(board[x][y]);
  if (board[x][y] == 'S')
    som++;
  isused[x][y] = 1;
  search(x + 1, y, cur + 1, som);
  search(x, y + 1, cur + 1, som);
  search(x - 1, y, cur + 1, som);
  search(x, y - 1, cur + 1, som);
  isused[x][y] = 0;
  st.pop();
}
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 0; i < 5; i++)
    cin >> board[i];

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      search(i, j, 0, 0);
    }
  }
  cout << ans;
}