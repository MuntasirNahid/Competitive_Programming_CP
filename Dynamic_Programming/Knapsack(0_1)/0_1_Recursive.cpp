/*
https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3&ab_channel=AdityaVerma

weight[],val[],W

choice diagram:
--------------
w1----> w1<=W ---1) include ,2) not include
        w1>W----3) not include


Base condition: Think of the smallest valid input
 in this case: weight and val array size is 0 and Weight W is 0.and returns profit  zero.




*/
#include <bits/stdc++.h>
#define pb push_back
#define pi acos(-1)
#define INF 1e18
#define MN7                      \
        ios::sync_with_stdio(0); \
        cin.tie(nullptr);
#define MOD 1000000007
#define popb pop_back()
#define popf pop_front()
using namespace std;
bool flag;
int knapsack(int weight[], int value[], int W, int n)
{
        // base case:
        if (n == 0 || W == 0) // size of array =0 or Weight=0
        {
                return 0; // profit =0
        }

        if (weight[n - 1] <= W)
        {
                return max(value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1), knapsack(weight, value, W, n - 1)); // max of include or not include
        }

        else
                return knapsack(weight, value, W, n - 1); // not include
}
int main()
{
        MN7;
        int n;
        cin >> n;
        int weight[n], value[n], max_profit, W;
        for (int i = 0; i < n; i++)
        {
                cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
                cin >> value[i];
        }
        cin >> W;

        max_profit = knapsack(weight, value, W, n);

        cout << "Maximum Profit = " << max_profit << endl;
}
//Time Complexity: O(2n). 
//As there are redundant subproblems.


/*
https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=4&ab_channel=AdityaVerma

Memoization:

Recursive code + 2 line of memoization = DP

we have to build the matrix for the variable which are changing.
So we will make the matrix of size  n+1( to store n element) and W+1.


*/

#include <bits/stdc++.h>
#define pb push_back
#define pi acos(-1)
#define INF 1e18
#define MN7                      \
        ios::sync_with_stdio(0); \
        cin.tie(nullptr);
#define MOD 1000000007
#define popb pop_back()
#define popf pop_front()
using namespace std;
bool flag;
int dp[102][1002]; // from constraint of n and W
int knapsack(int weight[], int value[], int W, int n)
{
        // base case:
        if (n == 0 || W == 0) // size of array =0 or Weight=0
        {
                return 0; // profit =0
        }
        if (dp[n][W] != -1) // stored before
                return dp[n][W];

        if (weight[n - 1] <= W)
        {
                return dp[n][W] = max(value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1), knapsack(weight, value, W, n - 1)); // max of include or not include
        }

        else
                return dp[n][W] = knapsack(weight, value, W, n - 1); // not include
}
int main()
{
        MN7;
        int n;
        cin >> n;
        int weight[n], value[n], max_profit, W;

        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
                cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
                cin >> value[i];
        }
        cin >> W;

        max_profit = knapsack(weight, value, W, n);

        cout << "Maximum Profit = " << max_profit << endl;
}
//Time Complexity: O(N*W)