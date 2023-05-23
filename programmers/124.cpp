#include <bits/stdc++.h>
using namespace std;
int n;
deque<string> v;
int main(void)
{
  cin >> n;

  while (n != 0)
  {
    if (n % 3 == 2)
      v.push_front("2");
    else if (n % 3 == 1)
      v.push_front("1");
    else if (n % 3 == 0)
      v.push_front("0");

    n /= 2;
  }

  for (auto c : v)
  {
    cout << c;
  }
}