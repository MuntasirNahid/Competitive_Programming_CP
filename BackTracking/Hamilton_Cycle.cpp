/*
Hamilton Path is a path that visits each vertex exactly once
Hamilton cycle(circuit)is  a  Hamilton Path , such thay there is an edge from the last vertex to the first vertex.(closed loop)

Hamiltonian Graph : any connected graph that contains a Hamilton Cycle


 if any hamilton function returns true then all the calling function will also return true



*/
#include <bits/stdc++.h>
#define sz 1000
using namespace std;
vector<int> graph[sz];
bool visited[sz];

bool HamiltonCycle(vector<int> &path, int v, int n)
{
    if (path.size() == n)
    {
        return true; // every node are added in the path
    }
    for (auto av : graph[v])
    {
        if (visited[av] == false)
        {
            visited[av] = true;
            path.push_back(av);
            if (HamiltonCycle(path, av, n))
            {
                return true; // if path.size() returns true.then every recursive caller vertex will return true
            }
            // if no hamilton cycle found following that adjacent vertex,we will backtrack
            visited[av] = false;
            path.pop_back();
        }
    }
    return false; // if no path found.
}
void init(int node)
{
    for (int i = 0; i < node; i++)
    {
        visited[i] = false;
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    init(node);
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> path;
    path.push_back(0); // source node;
    visited[0] = true;

    bool w = HamiltonCycle(path, 0, node);
    if (w)
    {
        cout << "HamiltonCycle Exists! The Cycle is : " << endl;
        for (auto x : path)
            cout << x << ",";
        cout << 0 << endl;
    }
    else
    {
        cout << "Hamilton Cycle DOesn't Exist!" << endl;
    }
}

/*
7 12
0 1
0 3
0 4
0 5
1 2
1 4
1 5
2 3
2 4
2 6
3 4
3 6

HamiltonCycle Exists! The Cycle is :
0,3,6,2,4,1,5,0

*/
