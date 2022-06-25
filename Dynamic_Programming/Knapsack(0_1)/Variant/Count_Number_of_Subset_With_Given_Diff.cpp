/*
Given an array Arr[] and a difference diff, find the number
of subsets that array can be divided so that each
the difference between the two subset is the given diff.

sum(s1)-sum(s2)=diff....(i)
sum(s1)+sum(s2)=sum(array)....(ii)

(i)+(ii)=> 2sum(s1)=diff+sum(array)
        =>sum(s1)=(diff+sum(array))/2;

so we have to find out how many subset are there avaibale with sum=sum(s1)
which is similar ot count_ of_subset with a given sum problem



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
    int n, sum, cnt = 0, diff;
    cin >> n >> diff;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt += arr[i];
    }
    sum = (diff + cnt) / 2; // sum of first subset

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

    cout << "Number of subset with difference " << diff << " is = " << dp[n][sum] << endl;
}