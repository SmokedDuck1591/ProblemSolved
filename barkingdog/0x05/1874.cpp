#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int cnt = 1;
  int n;
  stack<int> st;
  vector<char> v;
  cin >> n;

  while (n--)
  {
    int tmp;
    cin >> tmp;

    while (cnt <= tmp)
    {
      st.push(cnt++);
      v.push_back('+');
    }
    if (st.top() == tmp)
    {
      st.pop();
      v.push_back('-');
    }
    else
    {
      cout << "NO";
      return 0;
    }
  }

  for (auto c : v)
    cout << c << '\n';
}