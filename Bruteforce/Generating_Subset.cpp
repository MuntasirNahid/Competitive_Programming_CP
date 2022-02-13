#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> v = {1, 2, 3};
    n = v.size();
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                vec.push_back(v[j]);
        }
        for (auto x : vec)
            cout << x << " ";
        cout << "\n";
    }
}
/*
1
2
1 2
3
1 3
2 3
1 2 3
*/

// using recursion:

#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
void subset(int k)
{
    if (k == n)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
        return;
    }
    v.push_back(k);
    subset(k + 1);
    // return er ppor ager page e firey ashche
    v.pop_back();
    subset(k + 1);
}
int main()
{
    n = 3;
    subset(0);
}
/*
0 1 2
0 1
0 2
0
1 2
1
2

*/