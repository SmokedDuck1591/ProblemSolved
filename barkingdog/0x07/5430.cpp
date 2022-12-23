#include <bits/stdc++.h>
#include <sstream>

using namespace std;

deque<string> split(string input, char delimiter)
{
  deque<string> dq;
  stringstream ss(input);
  string temp;

  while (getline(ss, temp, delimiter))
  {
    dq.push_back(temp);
  }

  return dq;
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  while (n--)
  {
    string op;
    cin >> op;
    if (op == "[]")
    {
      cout << "error";
      break;
    }
    int num;
    cin >> num;

    string cmd;
    cin >> cmd;
    string subcmd = cmd.substr(1, cmd.length() - 2);

    deque<string> result = split(subcmd, ',');
    bool backorfront = true;
    bool breakornot = true;
    for (int i = 0; i < op.length(); i++)
    {
      if (op[i] == 'R')
      {
        if (backorfront)
          backorfront = false;
        else
          backorfront = true;
      }
      else
      {
        if (result.empty())
        {
          breakornot = false;
          break;
        }
        if (backorfront)
        {
          result.pop_front();
        }
        else
        {
          result.pop_back();
        }
      }
    }
    if (!breakornot)
    {
      cout << "error\n";
      break;
    }
    else
    {
      string ans = "[";
      while (!result.empty())
      {
        if (backorfront)
        {
          ans += *result.begin() + ',';
          result.pop_front();
        }
        else
        {
          string ch = *(--result.end());
          ans += ch + ',';
          result.pop_back();
        }
      }
      cout << ans << ']';
    }
  }
}