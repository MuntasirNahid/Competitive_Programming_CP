/*
https://youtu.be/F7wqWbqYn9g

Given an array arr[] of length N and an integer X, the task
is to find the number of subsets with a sum equal to X.

This is also a variation of the problem subset sum .
just difference is that we will use + operator instead of || operator.
Because it will store how many subset is equal to sum till now

It will return an integer instead of boolean.

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
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;

            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++) // i=element if array
    {
        for (int j = 1; j < sum + 1; j++) // j=sum
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]; // include or not include//here + operator

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "Number of Subset with sum = " << sum << " is available in the array = " << dp[n][sum] << endl;
}