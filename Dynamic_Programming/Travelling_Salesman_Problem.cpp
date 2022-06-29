/*
Given a set of cities and the distance between every pair of cities,
the problem is to find the shortest possible route that visits
every city exactly once and returns to the starting point.


https://www.youtube.com/watch?v=JE0JE8ce1V0&ab_channel=CodingBlocks

output of the TSP problem is minimum of the Total Hamiltonian Cycle

Bruteforce approach: Find all the permutation ,then compare. o(n!)

we have to store set of cities which has been visited so far

for backtrack we have to unvisit a city.this work will be done using bitmask.

Bitmask will represent what all cities we have been visited.

if cities=4 .. then mask=0000 means none of the cities have been visited

all cities visited ,mask=1111=2^4-1=(1<<n)-1

DCBA
0000 . If A city is visited then 0001

mask=give us which city is visited /unvisited
pos=from which city we are going to the next city

 dist[pos][0];//going back to origin from current city

mask will go ->2^n and there are n cities.. so we will create a dp table of dp[2^n][n] . O(2^n *n)



*/
#include <bits/stdc++.h>
using namespace std;
int n = 4;
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};
int dp[16][4]; // dp[2^n][n]
int VISITED_DONE = (1 << n) - 1;
int tsp(int mask, int pos)
{
    // base case
    if (mask == VISITED_DONE)
    {
        return dist[pos][0]; // current position to origin(cycle fulfilled)
    }

    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    // let's visit unvisited city

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0) // not visited city
        {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city); // recursively next city gula visit..
            ans = min(ans, newAns);
        }
    }
    dp[mask][pos] = ans;
    return dp[mask][pos];
}

int main()
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "Minimum HamiltonianPath Cost = " << tsp(1, 0) << endl; // tasp(mask,pos)//mask = 0001, pos=0(1st city)
}

/*
TSP using branch and Bound Technique:
https://youtu.be/LMjDeWIkih4
row reduce,column reduce,cost..booooom
*/