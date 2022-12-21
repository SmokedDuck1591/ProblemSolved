#include <bits/stdc++.h>
using namespace std;
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  stack<int> st;

  while (n--)
  {
    int tmp;
    cin >> tmp;
    if (tmp == 0)
      st.pop();
    else
      st.push(tmp);
  }
  int ans = 0;
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }
  cout << ans;
}