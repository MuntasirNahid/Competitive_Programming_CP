/*
Given a value N, if we want to make change for N cents, and we have infinite supply
of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
Example:
for N = 4 and S = {1,2,3},
 there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.

it is similar as count of subset sum problem.But ib this case it is unbounded


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
            if (i == 0)
                dp[i][j] = 0;

            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++) // i=element of coin array
    {
        for (int j = 1; j < amount + 1; j++) // j=amount
        {
            if (coin[i - 1] <= j)
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j]; // include or not include

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "Number of way to pay the amount = " << amount << " is available in the coin array = " << dp[n][amount] << endl;
}