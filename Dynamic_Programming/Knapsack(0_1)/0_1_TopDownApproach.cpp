/*
https://www.youtube.com/watch?v=ntCGbPMeqgg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5&ab_channel=AdityaVerma

Known as real dynamic programming.Best approach

In this approach we will omit recursive call and will get the answer from the table

To avoid stack overflow error(due to excessive recursive call) we use this approach

Here base condition of recursive call turns into initialization
so when n=0 row or w=0 column comes we will return 0


we will get the output at dp(n,w);
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
    int max_profit, value[n], weight[n];
    int dp[n + 1][w + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // initializing ->recursive calls base case
        }
    }

    for (int i = 1; i < n + 1; i++) // i=n
    {
        for (int j = 1; j < w + 1; j++) // j=w
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]); // i=n,j=w,,transforming recursive calls to iterative call;max(include,not include)
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // not include
            }
        }
    }

    max_profit = dp[n][w];

    cout << "Maximum Profit: " << max_profit << endl;
}

//Time Complexity: O(N*W)