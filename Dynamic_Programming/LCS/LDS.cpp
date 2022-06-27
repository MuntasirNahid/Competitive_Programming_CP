/*
GFG

Given an array of N integers, find the length of the longest subsequence
of a given sequence such that all elements of the subsequence are sorted in strictly decreasing order.

Input: arr[] = [15, 27, 14, 38, 63, 55, 46, 65, 85]
Output: 3
Explanation: The longest decreasing subsequence is {63, 55, 46}
*/

#include <bits/stdc++.h>
using namespace std;
int LDS(int arr[], int n)
{
    // Let arr[0…n-1] be the input array and lds[i] be the length of the LDS ending at
    // index i such that arr[i] is the last element of the LDS.
    int lds[n];
    for (int i = 0; i < n; i++)
        lds[i] = 1; // initializing with zero
    // this means min size of lds

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1) // 1 thakle 2..
            {
                lds[i] = lds[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lds[i]);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = LDS(arr, n);
    cout << "Longest Decreasing Subsequence length= " << ans << endl;
}
//Time Complexity : O(n^2)
/*
9
15 27 14 38 63 55 46 65 85

Longest Decreasing Subsequence length= 3
*/