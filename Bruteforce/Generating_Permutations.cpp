#include <bits/stdc++.h>
#define ll long long
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
ll t, n, i, j, k, a, b, c, d, p, q, r, x, y, z, m, cnt, ans;
bool flag;
string s, s2;

void nahid()
{
    vector<ll> v = {1, 1, 3, 4};
    do
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}
int main()
{
    MN7;
    nahid();
}
/*
1 1 3 4
1 1 4 3
1 3 1 4
1 3 4 1 
1 4 1 3
1 4 3 1
3 1 1 4
3 1 4 1
3 4 1 1
4 1 1 3
4 1 3 1
4 3 1 1
*/