#include <bits/stdc++.h>
using namespace std;
stack<pair<long, long>> st;
int arr[500002];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int tmp;
    cin >> tmp;
    while (!st.empty() && st.top().second < tmp)
      st.pop(); // 스택이 비어있지 않고 새로 입력하는 수보다 스택이 작을 경우 스택을 비워준다.
    if (!st.empty() && st.top().second >= tmp)
      arr[i] = st.top().first;
    st.push({i, tmp});
  }

  for (int i = 1; i <= n; i++)
    cout << arr[i] << ' ';
}