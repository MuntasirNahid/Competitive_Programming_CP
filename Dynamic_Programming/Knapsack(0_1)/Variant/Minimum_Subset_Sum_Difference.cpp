/*
https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10&ab_channel=AdityaVerma

Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of
abs(sum(Subset1) – sum(Subset2)) should be minimum.

this is similar to equal sum partition problem

 now we have a range: sum of all elements - null subset
  which means the range is (0-S) where S = sum of all elements of the array
  if we find s1. then s2=range(sum of array)-s1
we have to minimize :abs(s2-s1) =abs(range-2s1)

we will take the value of s1 less than or equal s/2(hamari marzi) .. and will find subset of subset sum below or equal s/2

last row of matrix will show us how many subset making is possible between 0 to range. we will store it in a vector(only below or equal 0- s/2 range)

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

    int i = n;
    vector<int> v;
    for (int j = 0; j <= sum / 2; j++)
    {
        if (dp[i][j])
        {
            v.push_back(j);
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        int x = sum - 2 * v[i];
        mn = min(mn, x);
    }
    cout << "Minimum sum difference of two subset derived from this array = " << mn << endl;
}