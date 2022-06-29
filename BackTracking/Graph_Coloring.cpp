/*
GFG

Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours such that no two
adjacent vertices of the graph are colored with the same color.
Here coloring of a graph means the assignment of colors to all vertices.

*/
#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V],
            int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i]) // the edge exists and color matches with adjacent color(if both  of them is true then return false)
            return false;

    return true;
}

bool AnswerCheck(bool graph[V][V], int m,
                 int color[], int v)
{

    /* base case: If all vertices are
       assigned a color then return true */
    if (v == V)
        return true;

    /* Consider this vertex v and
       try different colors */
    for (int c = 1; c <= m; c++)
    {

        /* Check if assignment of color
           c to v is fine*/
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            /* recur to assign colors to
               rest of the vertices */
            if (AnswerCheck(
                    graph, m, color, v + 1) == true)
                return true;

            /* If assigning color c doesn't
               lead to a solution then remove it */
            color[v] = 0; // backtracking
        }
    }

    /* If no color can be assigned to
       this vertex then return false */
    return false;
}

bool graphColoring(bool graph[V][V], int m)
{

    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call AnswerCheck() for vertex 0
    if (AnswerCheck(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

    // Print the solution
    printSolution(color);
    return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
    cout << "Solution Exists:"
         << " Following are the assigned colors"
         << "\n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";

    cout << "\n";
}

int main()
{

    /* Create following graph and test
       whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    // Number of colors
    int m = 3;
    graphColoring(graph, m);
    return 0;
}
/*
Solution Exists: Following are the assigned colors
1  2  3  2
*/