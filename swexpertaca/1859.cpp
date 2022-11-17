#include <bits/stdc++.h>
using namespace std;
int testCase, iNum, priceNum;

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> testCase;
  while (--testCase)
  {
    int price[1000001];
    int highPrice = 0;
    while (--iNum)
    {
      for (int i = 0; i < priceNum; i++)
        cin >> price[i];
    }
    for (int i = priceNum - 1; i >= 0; i--)
    {
      if (highPrice < price[i])
      {
        
      }
    }
  }
}