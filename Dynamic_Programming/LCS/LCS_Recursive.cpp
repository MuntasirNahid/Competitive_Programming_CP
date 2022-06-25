/*
we have to print the longest common subsequence's length
substring->continuous
subsequence->not have to be continuous

if last character of both string doesn't matches.
we have two option:
1)Take first string full and take 2nd string without last unmatched character
2)Take 2nd string full and take 1st string without unmatched last character

if last character matches
we will call recursion without the last character of both string

*/
#include <bits/stdc++.h>
using namespace std;
int LCS(string x, string y, int n, int m)
{
    // base case:
    if (n == 0 || m == 0)
        return 0; // LCS=0

    if (x[n - 1] == y[m - 1])
        return (1 + LCS(x, y, n - 1, m - 1)); //+1 beacuse 1 item matched

    else
        return (max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1))); // either minimizing x or y
}
int main()
{
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
