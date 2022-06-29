/*
ncr means taking r elements from n elements and making combination.duplicate combination is not allowed. (1,2) and (2,1) is duplicate
*/
#include <bits/stdc++.h>
using namespace std;

void combination(int arr[], int r, int st, int en, vector<int> &temp)
{

    if (r == temp.size())
    {
        for (auto x : temp)
            cout << x << " ";
        cout << endl;
        return;
    }
    for (int i = st; i <= en; i++)
    {
        temp.push_back(i + 1);
        combination(arr, r, i + 1, en, temp); // recursive tree call
        temp.pop_back();                      // backtrack
    }
}
int main()
{
    int n, r;
    cin >> n >> r;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> temp;
    combination(arr, r, 0, n - 1, temp);
}