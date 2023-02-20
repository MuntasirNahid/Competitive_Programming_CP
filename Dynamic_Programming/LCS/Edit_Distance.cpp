/*
Given two strings str1 and str2 and below operations that can be
 performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

1)Insert
2)Remove
3)Replace
All of the above operations are of equal cost.

it is basically LCS problem.

below implementation doesnot work for all cases
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int z = max(n, m);      // max size string
    int ans = z - dp[n][m]; // max size of string - LCS
    cout << "Number Of Insert/Delete/Replace needed: " << ans << endl;
}
// Time Complexity: O(m x n)
/*
sunday saturday
Number Of Insert/Delete/Replace needed: 3
*/
