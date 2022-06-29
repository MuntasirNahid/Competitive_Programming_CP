/*
A permutation also called an “arrangement number” or “order,” is
a rearrangement of the elements of an ordered list S into a
one-to-one correspondence with S itself. A string of length n has n! permutation.
*/

// string:

#include <bits/stdc++.h>
using namespace std;

void permute(string s, int l, int r)
{
    if (l == r)
        cout << s << endl;

    for (int i = l; i <= r; i++)
    {
        swap(s[i], s[l]);     // swapping elements
        permute(s, l + 1, r); // permutation called
        swap(s[i], s[l]);     // backtrack kore abar uporer step e uthchi.
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    permute(s, 0, n - 1);
}
/*
ABC
ACB
BAC
BCA
CBA
CAB
*/

// array:

#include <bits/stdc++.h>
using namespace std;
int n = 3;
void permute(int arr[], int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    for (int i = l; i <= r; i++)
    {
        swap(arr[i], arr[l]);
        permute(arr, l + 1, r);
        swap(arr[i], arr[l]);
    }
}

int main()
{

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    permute(arr, 0, n - 1);
}
/*
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2
*/