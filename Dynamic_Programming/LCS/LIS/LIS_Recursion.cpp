/*
https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/

The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence’s
elements are in sorted order, lowest to highest,
and in which the subsequence is as long as possible.
This subsequence is not necessarily contiguous or unique

For example, the longest increasing subsequence of [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15] is [0, 2, 6, 9, 11, 15].[0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15] are other increasing
subsequences of equal length in the same input sequence.
*/

#include <bits/stdc++.h>
using namespace std;
int LIS(int arr[], int i, int n, int prev)
{
    // Base case: nothing is remaining
    if (i == n)
        return 0;
    // case 1: exclude the current element and process the
    // remaining elements

    int excl = LIS(arr, i + 1, n, prev);

    // case 2: include the current element if it is greater
    // than the previous element in LIS
    int incl = 0;
    if (arr[i] > prev)
    {
        incl = 1 + LIS(arr, i + 1, n, arr[i]);
    }
    int ans = max(excl, incl);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = LIS(arr, 0, n, INT_MIN);
    cout << "Longest Increasing Subsequence length= " << ans << endl;
}
/*
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15


Longest Increasing Subsequence length= 6
*/