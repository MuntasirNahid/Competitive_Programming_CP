/*
https://www.youtube.com/watch?v=0jWeUdxrGm4&ab_channel=Errichto

This is  also known as Dense Table.

we use power of two in this case

 m[i][j]=min(m[i][j-1],m[i+??][j-1]);//j= power of two
=>m[i][j]=min(m[i][j-1].m[i+1<<(j-1)][j-1])

we use this sparse table do solve the problem of range minimum query


*/
#include <bits/stdc++.h>
using namespace std;

int lookup[500][500];

void SparseTable(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];

    for (int j = 1; (1 << j) <= n; j++)
    {

        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            lookup[i][j] = min(lookup[i][j - 1], lookup[i + (1 << j - 1)][j - 1]);
        }
    }
}
int query(int L, int R)
{
    int len = R - L + 1;

    int j = (int)log2(len);
    return min(lookup[L][j], lookup[R - (1 << j) + 1][j]);
}
int main()
{
    int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    int n = sizeof(a) / sizeof(a[0]);
    SparseTable(a, n);
    cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;
    return 0;
}
/*
0
3
12

Time Complexity: O(n*Logn)

Auxiliary Space: O(n*Logn)
So sparse table method supports query operation in O(1) time with O(n Log n) preprocessing time and O(n Log n) space.
*/