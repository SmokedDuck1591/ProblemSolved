#include <bits/stdc++.h>
using namespace std;

int k, arr[15], non[15];
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    cin >> k;
    if (!k)
      break;

    for (int i = 0; i < k; i++)
      cin >> arr[i];
    for (int i = 6; i < k; i++)
      non[i] = 1;
    do
    {
      for (int i = 0; i < k; i++)
      {
        if (!non[i])
          cout << arr[i] << " ";
      }
      cout << '\n';
    } while (next_permutation(non, non + k));
    cout << '\n';
  }
}