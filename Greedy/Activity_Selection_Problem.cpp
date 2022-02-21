/*
Also known as scheduling problem
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
*/
// we can easily solve this problem using Finish Time of each activity

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void nahid()
{
    ll a, b, n;
    cin >> n;
    vector<pair<ll, ll>> vp;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vp.push_back({b, a}); // finish time,start time;
    }
    sort(vp.begin(), vp.end());
    cout << "The selected activities are: ";
    int cnt = 1;
    int i = 0;
    cout << "{ (" << vp[i].second << " " << vp[i].first << ") ";
    for (int j = 1; j < n; j++)
    {
        if (vp[j].second >= vp[i].first)
        {
            cout << " (" << vp[j].second << " " << vp[j].first << " ) ";
            cnt++;
            i = j;
        }
    }
    cout << "}" << endl
         << "Total Number of Activity Can be done = " << cnt << endl;
}

int main()
{
    nahid();
}
/*
6
5 9
1 2
3 4
0 6
5 7
8 9

The selected activities are: { (1 2)  (3 4 )  (5 7 )  (8 9 ) }
Total Number of Activity Can be done = 4




*/