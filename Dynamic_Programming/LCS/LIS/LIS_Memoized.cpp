// Bottom_Up
#include <bits/stdc++.h>
using namespace std;
int LIS(int arr[], int n)
{
    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1; // initializing with zero
    // this means min size of lis

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) // 1 thakle 2..
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis[i]);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = LIS(arr, n);
    cout << "Longest Increasing Subsequence length= " << ans << endl;
}
/*
6
1 4 3 5 2 8


Longest Increasing Subsequence length= 4
*/