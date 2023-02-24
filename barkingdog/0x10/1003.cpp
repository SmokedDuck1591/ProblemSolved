#include <bits/stdc++.h>
using namespace std;
int arr[42];

int fibo()
{
  arr[0] = arr[1] = 1;
  for (int i = 2; i <= 40; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[40];
}

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  fibo();
  while (n--)
  {
    int tmp;
    cin >> tmp;

    if (tmp == 0)
      cout << 1 << ' ' << 0;
    else if (tmp == 1)
      cout << 0 << ' ' << 1;
    else
    {
      cout << arr[tmp - 2] << ' ' << arr[tmp - 1];
    }
    cout << '\n';
  }
}