/*
https://youtu.be/I-l6PBeERuc

Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
what is the minimum number of coins to make the change?

This problems initialization have some twist

When we have 0 coin but we need sum =1 , logically it is impossible .But mathematically.how much minimum coin we need to make sum=1?
we need infinite number of coins.Which will be denoted by INT_MAX-1
and so on  for the whole i=0 row

Why INT_MAX-1?
- further when we add +1 .. For INT_MAX-1+1=INT_MAX.. if we used INT_MAX,then it will overflow and will give negetive value..

when we have 1 element in the array ,but we need 0 sum. we will take minimum zero coin.So,for j=0(without 0,0)column all will be initialized with 0

we have to initialize second row too,in this problem. If sum/arr[0] then we will put sum/arr[0] ,else we will put INT_MAX-1
coin include ,that's why +1

*/

#include <bits/stdc++.h>
#define pb push_back
#define pi acos(-1)
#define INF 1e18
#define MN7                  \
    ios::sync_with_stdio(0); \
    cin.tie(nullptr);
#define MOD 1000000007
#define popb pop_back()
#define popf pop_front()
using namespace std;
bool flag;
int main()
{
    MN7;
    int n, amount;
    cin >> n >> amount;
    int coin[n];
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    int dp[n + 1][amount + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 0;

            if (i == 0)
                dp[i][j] = INT_MAX - 1; // infinity
        }
    }
    int i = 1;
    for (int j = 1; j < amount + 1; j++) // second row. when array element =1
    {
        if (j % coin[0] == 0)
        {
            dp[i][j] = j / coin[0];
        }
        else
            dp[i][j] = INT_MAX - 1;
    }

    for (int i = 2; i < n + 1; i++) // i=element of coin array
    {
        for (int j = 1; j < amount + 1; j++) // j=amount
        {
            if (coin[i - 1] <= j)
                dp[i][j] = min(dp[i][j - coin[i - 1]] + 1, dp[i - 1][j]); // include(count +1) or not include

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "Minimum Number of coins needed to pay the amount = " << amount << " is available in the coin array = " << dp[n][amount] << endl;
}