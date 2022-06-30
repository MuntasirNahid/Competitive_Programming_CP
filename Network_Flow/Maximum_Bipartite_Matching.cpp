/*
GFG

A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges share an endpoint.
 A maximum matching is a matching of maximum size (maximum number of edges).
In a maximum matching,if any edge is added to it, it is no longer a matching.
There can be more than one maximum matchings for a given Bipartite Graph.


it basically uses the idea of ford fulkerson algorithm

*/
// Bipartite matching.
#include <iostream>
#include <string.h>
using namespace std;

// M is number of applicants
// and N is number of jobs
#define M 6
#define N 6

// A DFS based recursive function
// that returns true if a matching
// for vertex u is possible
bool bpm(bool bpGraph[M][N], int u,
         bool seen[], int occupied[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in
        // job v and v is not visited
        if (bpGraph[u][v] && !seen[v])
        {
            // Mark v as visited
            seen[v] = true;

            // If job 'v' is not assigned to an
            // applicant OR previously assigned
            // applicant for job v (which is occupied[v])
            // has an alternate job available.
            // Since v is marked as visited in
            // the above line, occupied[v] in the following
            // recursive call will not get job 'v' again
            if (occupied[v] < 0 || bpm(bpGraph, occupied[v],
                                       seen, occupied))
            {
                occupied[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number
// of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
    // An array to keep track of the
    // applicants assigned to jobs.
    // The value of occupied[i] is the
    // applicant number assigned to job i,
    // the value -1 indicates nobody is
    // assigned.
    int occupied[N];

    // Initially all jobs are available
    memset(occupied, -1, sizeof(occupied));

    // Count of jobs assigned to applicants
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen
        // for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, occupied))
            result++;
    }
    return result;
}

int main()
{
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0},
                          {1, 0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1}};

    cout << "Maximum number of applicants that can get job is = "
         << maxBPM(bpGraph) << endl;

    return 0;
}

// Maximum number of applicants that can get job is = 5