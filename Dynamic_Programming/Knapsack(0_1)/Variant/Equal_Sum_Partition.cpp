/*
Partition problem is to determine whether a given set can be partitioned
into two subsets such that the sum of elements in both subsets is the same.

it is only possible when the sum of array is even.(2S)

it is also same as the problem subset sum .. we have to find subset with sum  s (means(sum of array/2))

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
void equal_sum_partition(int arr[], int n, int sum)
{
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
    cout << "Equal Sum partition";
    dp[n][sum] ? cout << " is" : cout << " is not ";
    cout << " available in the SET." << endl;
}
int main()
{
    MN7;
    int n, sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 2)
    {
        cout << "Equal Sum partition is not possible in this set!" << endl;
    }
    else
    {
        equal_sum_partition(arr, n, sum / 2);
    }
}