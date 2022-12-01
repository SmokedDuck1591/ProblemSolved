#include <bits/stdc++.h>
using namespace std;
int cnt[26];

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  string tmp;
  cin >> tmp;

  for (char i : tmp)
    cnt[i - 'a']++;

  for (int i : cnt)
    cout << i << ' ';
}