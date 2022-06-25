/*
Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly.
This is different from classical Knapsack problem, here we are
allowed to use unlimited number of instances of an item.



4 variations:
1)Rod cutting
2)CoinChange 1(Max Number of Coin)
3)Coin change 2(Min Number of Coin)
4)Maximum Ribbon cut

main difference is  multiple occurancce of same item is allowed in this version of knapsack

if we decide we will not include the item ,we will never comeback to this item.

if we decide to include,we can add the item multiple time.

same initialization as 0/1 knapsack.
only change of code is i-1 will be replaced in i ,when we include.


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
    int n, w;
    cin >> n >> w;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int dp[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++) // i=element of array
    {
        for (int j = 1; j < w + 1; j++) // j=w
        {
            if (weight[i - 1] <= j)
                dp[i][j] = max(value[i - 1] + dp[i][j - weight[i - 1]], dp[i - 1][j]); // include(i will not decrease as we can process it again) or not include

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "Maximum Profit (Unbounded Knapsack) = " << dp[n][w] << endl;
}
/*

4 8
1 3 4 5
10 40 50 70

Maximum Profit (Unbounded Knapsack) = 110
*/