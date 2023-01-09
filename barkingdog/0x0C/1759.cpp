#include <bits/stdc++.h>
using namespace std;
int n, k;
char arr[17];
int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;

  for (int i = 0; i < k; i++)
    cin >> arr[i];
  sort(arr, arr + k);

  do
  {
    string tmp;
    int acnt = 0;
    int bcnt = 0;
    bool iflag = true;
    for (int i = 0; i < n; i++)
    {
      tmp += arr[i];
      if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
        acnt++;
      else
        bcnt++;
      if (i > 0 && arr[i - 1] > arr[i])
        iflag = false;
    }
    if (acnt >= 1 && bcnt >= 2 && iflag)
    {
      cout << tmp << '\n';
    }
  } while (next_permutation(arr, arr + k));
}