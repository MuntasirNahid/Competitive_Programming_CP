/*
https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12&ab_channel=AdityaVerma

Given a list of non-negative integers, a1, a2, ..., an, and a target, S.
Now you have 2 symbols + and -. For each integer, you should choose one
from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

https://leetcode.com/problems/target-sum/

This is basically(same) count number of subset with a given difference problem.


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
    int n, sum, cnt = 0, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt += arr[i];
    }
    sum = (target + cnt) / 2; // sum of first subset

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

    cout << "The ways to assign symbols to make sum of integers equal to target = " << dp[n][sum] << endl;
}