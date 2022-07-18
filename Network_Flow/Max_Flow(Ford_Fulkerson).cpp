/*
https://youtu.be/_UcOALraATY

it is a greedy approach for calculating the maximum flow in a network or a graph.
It is also known as "augmenting path algorithm".
it is also referred as "Edmonds-Karp algorithm" Because some optimizaton were done by Edmonds Karp.

Residual Capacity: It is the capacity of the edge after subtracting the flow from the maximum capacity
-----------------
Rresidual graph: A graph with the same vertices and same edges,but we use residual capacities as capacities.
---------------
Augmenting Path: An augmenting(means increasing)path is a simple path in the residual graph,i.e along the edges whose
residual capacity is positive
*/

/*
Ford FUlkerson uses DFS algortihm,Edmonds karp is same shit as Ford Fulkerson. But it uses BFS instead of BFS.. So in some special case(Following) it is more
efficient than Ford Fulkerson.


*/

#include <bits/stdc++.h>
using namespace std;

int bfs(int source, int sink, vector<int> &parent, vector<vector<int>> &residualGraph)
{
    fill(parent.begin(), parent.end(), -1); // every bfs call filling parent vector with zero
    int V = residualGraph.size();
    parent[source] = -2; // parent's source identified with -2
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});
    while (!q.empty())
    {
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        for (int av = 0; av < V; av++)
        {
            if (u != av && parent[av] == -1 && residualGraph[u][av] != 0) // till residual graph is empty(no flow possible)
            {
                parent[av] = u;
                int min_cap = min(capacity, residualGraph[u][av]);
                if (av == sink)
                    return min_cap;
                q.push({av, min_cap});
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>> &graph, int source, int sink)
{
    vector<int> parent(graph.size(), -1);

    vector<vector<int>> residualGraph = graph;
    int min_cap = 0, max_flow = 0;
    while (min_cap = bfs(source, sink, parent, residualGraph)) // while min_cap is giving us positive value
    {
        max_flow += min_cap;
        int u = sink;
        while (u != source)
        {
            int v = parent[u];
            residualGraph[v][u] -= min_cap; // frontedge -
            residualGraph[u][v] += min_cap; // backedge +
            u = v;
        }
    }
    return max_flow;
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<int>> graph(node, vector<int>(node, 0));
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    cout << "Maximum Flow(Ford_Fulkerson) = " << ford_fulkerson(graph, 0, node - 1) << " unit." << endl; // grsph,source,sink
    return 0;
}

/*
6 7
0 1 4
0 3 3
1 2 4
2 3 3
2 5 2
3 4 6
4 5 6

Maximum Flow(Ford_Fulkerson) = 7 unit.




Limitations:
The complexity of Ford-Fulkerson algorithm cannot be accurately
 computed as it all depends on the path from source to sink.
  For example, considering the network shown below, if each time,
   the path chosen are S-A-B-T  and S-B-A-T  alternatively, then it can take
    a very long time. Instead, if path chosen are only S-A-T  and S-B-T, would also generate the maximum flow.

s-a-1000
s-b-1000
a-b-1
b-t-1000
a-t-1000





*/
