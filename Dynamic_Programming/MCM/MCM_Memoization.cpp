/*
Bottom Up Dp
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; // sizeof n
int Find_MCM(int arr[], int i, int j)
{
    // base case:
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_sum = Find_MCM(arr, i, k) + Find_MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(ans, temp_sum);
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = Find_MCM(arr, 1, n - 1);
    cout << "Minimum number of Multiplication needed = " << ans << endl;
}
// Time Complexity: O(n3 )

// Auxiliary Space: O(n2) ignoring recursion stack space
/*
5
40 20 30 10 30

output:
Minimum number of Multiplication needed = 26000
*/
