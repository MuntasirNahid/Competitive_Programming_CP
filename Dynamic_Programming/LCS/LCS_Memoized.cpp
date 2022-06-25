/*
dp[n+1][m+1]

*/
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int LCS(string x, string y, int n, int m)
{
    // base case:
    if (n == 0 || m == 0)
        return 0; // LCS=0

    if (dp[n][m] != -1)
        return dp[n][m];

    if (x[n - 1] == y[m - 1])
        return dp[n][m] = (1 + LCS(x, y, n - 1, m - 1)); //+1 beacuse 1 item matched

    else
        return dp[n][m] = (max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1))); // either minimizing x or y
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    int ans = LCS(x, y, n, m);
    cout << "Longest common subsequence size length = " << ans << endl;
}
/*
abcdegh
abhdgeh

Longest common subsequence size length = 5
abdeh/abdgh
*/