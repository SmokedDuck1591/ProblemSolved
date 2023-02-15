#include <bits/stdc++.h>
using namespace std;
int arr[2000002];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  while (n--)
  {
    int tmp;
    cin >> tmp;
    arr[tmp + 1000000]++;
  }

  for (int i = 0; i < 2000001; i++)
    for (int j = 0; j < arr[i]; j++)
      cout << i - 1000000 << '\n';
}