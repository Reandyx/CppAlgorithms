#include <iostream>
#include <vector>
using std::cout;
using std::vector;

struct Edge {
    int src, dest;
};

class Graph
{
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const& edges, int n)
    {
        adjList.resize(n);

        for (auto& edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

void DFS(Graph const& graph, int v, vector<bool>& discovered)
{
    discovered[v] = true;

    cout << v << " ";

    for (int u : graph.adjList[v])
    {
        if (!discovered[u]) {
            DFS(graph, u, discovered);
        }
    }
}

int main()
{
    vector<Edge> edges = {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    };

    int n = 13;

    Graph graph(edges, n);

    vector<bool> discovered(n);

    for (int i = 0; i < n; i++)
    {
        if (discovered[i] == false) {
            DFS(graph, i, discovered);
        }
    }

    return 0;
}