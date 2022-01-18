#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>
using namespace std;

class Graph
{
    int V;
    vector<int>* adj;
    vector<int>* wgt;
    int* prev;
public:
    Graph(int V);
    void addEdge(int v, int w, int wgt);
    void BFS(int s, int t);
    void displayPath(int f);
};

Graph::Graph(int V)     //constructor
{
    this->V = V;
    adj = new vector<int>[V];
    wgt = new vector<int>[V];
    prev = new int[V];
}

void Graph::addEdge(int v, int w, int wt) 
{
    adj[v].push_back(w);
    wgt[v].push_back(wt);
    adj[w].push_back(v);
    wgt[w].push_back(wt);
}

void Graph::BFS(int s, int t) //logic
{     
    bool* visited = new bool[V];

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }

    list<int> queue;
    int current;
    visited[s] = true;
    prev[s] = -1;
    queue.push_back(s);
    vector<int>::iterator i;

    while (!queue.empty())
    {
        current = queue.front();
        queue.pop_front();

        for (i = adj[current].begin(); i != adj[current].end(); ++i)
        {
            if (!visited[*i])
            {
                prev[*i] = current;
                visited[*i] = true;
                if (*i == t)
                {
                    cout << "found" << endl;
                    displayPath(t);
                    exit(0);
                }
                queue.push_back(*i);
            }
        }
    }
}

void Graph::displayPath(int f)
{
    int p = f;
    int q;
    int pos;
    int pathlen = 0;
    cout << "Path is: ";

    while (p != -1)
    {
        cout << "->" << p;
        q = prev[p];
        if (q != -1)
        {
            pos = find(adj[p].begin(), adj[p].end(), q) - adj[p].begin();
            pathlen = pathlen + wgt[p].at(pos);
        }
        p = q;
    }
    cout << endl;
    cout << "pathlength : " << pathlen;
    cout << endl;
}

int main()
{
    int n, e, a, b, c;
    int vstart, vend;
    cout << "No. of vertices:";
    cin >> n;
    cout << "No. of edges:";
    cin >> e;
    Graph g(n);
    cout << "Enter the list of edges in the format ; v1 v2 weight:";
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    cout << "Enter the start vertex:";
    cin >> vstart;
    cout << "Enter the end vertex:";
    cin >> vend;
    g.BFS(vend, vstart);
    return 0;
}