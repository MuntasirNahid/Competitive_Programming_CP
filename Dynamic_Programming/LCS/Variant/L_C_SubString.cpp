/*
Substring is continuous
abcde
abfce
common substring: ab,c,e
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
                dp[i][j] = 1 + dp[i - 1][j - 1]; // increasing the length
            else
                dp[i][j] = 0;
        }
    }
    int max_len = -1;

    for (int i = 0; i < +n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            max_len = max(max_len, dp[i][j]); // max of dp matrix
        }
    }
    cout << "Longest common substring size length = " << max_len << endl;
}
/*
abcde
abfce

Longest common substring size length = 2
ab,c,e
*/
