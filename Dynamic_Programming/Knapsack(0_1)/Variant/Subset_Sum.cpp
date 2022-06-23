/*
Given a set of non-negative integers, and a value sum,
determine if there is a subset of the given set with sum equal to given sum.

sum of empty subset is 0

so in this case in initialization if column(sum)=0 then true for every row but
if n=0(number of element in the array),then false for every column excluding (0,0)

Max will be replaced by or(||)..which means true or false

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

    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;

            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i < n + 1; i++) // i=element if array
    {
        for (int j = 1; j < sum + 1; j++) // j=sum
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]; // include or not include

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << "Subset with sum = " << sum;
    dp[n][sum] ? cout << " is" : cout << " is not ";
    cout << " available in the array." << endl;
}