//have n point.have toi find minimum distance between two point
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
//ll t, n, i, j, k, a, b, c, d, p, q, r, x, y, z, m, cnt, ans;
bool flag;
string s, s2;
double sq(double x)
{
    return x * x;
}
void nahid()
{
    int n;
    cin >> n;
    vector<pair<double, double>> vp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].first >> vp[i].second;
        double inf = 1e9;
        for (int i = 0; i < n; i++)
        
            for (int j = i + 1; j < n; j++)
            
                inf = min(inf, sqrt(sq(vp[i].first - vp[j].first) + sq(vp[i].second - vp[j].second)));
            
            cout << inf << endl;
        
    }
}
int main()
{
    MN7;
    //cin >> t;
    // while(t--)
     nahid();
}