/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete
and insert the minimum number of characters from/in
str1 to transform it into str2. It could be possible
that the same character needs to be removed/deleted from
one point of str1 and inserted to some another point.

a:heap
b:pea

to convert a to b
we need minimum 3 operation
insertion: p
deletion: h p
output: 1 2

number of deletion = a.size()-LCS
number of insertion = b.size()-LCS

Time Complexity: O(m * n)
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
    int insertion = n - dp[n][m];
    int deletion = m - dp[n][m];

    cout << "Number of insertion and deletion needed to convert string "
         << "\"" << x << "\""
         << " to "
         << "\"" << y << "\""
         << ":" << endl
         << "insertion: " << insertion << endl
         << "deletion: " << deletion << endl;
}
/*

heap
pea

Number of insertion and deletion needed to convert string "heap" to "pea":
insertion: 2
deletion: 1

*/
