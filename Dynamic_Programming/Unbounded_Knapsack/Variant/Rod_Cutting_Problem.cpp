/*
https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=14&ab_channel=AdityaVerma

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the  maximum value obtainable by cutting up the rod and selling the pieces.

if length array is not given we will pick it ourselves.which is 1-n

This is a variation of unbounded knapsack.As we can pick a length multiple number of times

Code is same as unbounded knapsack
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
    int n, len;
    cin >> n >> len;
    int length[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> length[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int dp[n + 1][len + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < len + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++) // i=element if array
    {
        for (int j = 1; j < len + 1; j++) // j=len
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(value[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]); // include or not include

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "Maximum Profit after cutting and selling rod = " << dp[n][len] << endl;
}
/*

8 8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20

Maximum Profit after cutting and selling rod = 22

cutting into two pieces of length 6 and 2
*/
