#include <iostream>
#include <limits.h>
#include <list>
#include <queue>

class Graph {
private:
    int v;
    std::list<int>* adj;

    void dfsUtil(int u, bool*& visited);

public:
    Graph(int v);
    void addEdge(int u, int v);
    void bfs(int u);
    void dfs(int u);
    std::list<int> dijkstra(int start);
};

Graph::Graph(int v)
{
    this->v = v;
    this->adj = new std::list<int>[v];
}

void Graph::addEdge(int u, int v)
{
    this->adj[u].push_back(v);
}

void Graph::bfs(int v)
{
    std::queue<int> q;
    q.push(v);

    bool* visited = new bool[this->v];
    for (int i = 0; i < this->v; i++)
        visited[i] = false;

    visited[v] = true;

    while (!q.empty()) {
        v = q.front();
        std::cout << v << " ";
        q.pop();

        for (auto&& u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    std::cout << "\n";
}

void Graph::dfsUtil(int u, bool*& visited)
{
    visited[u] = true;
    std::cout << u << " ";

    for (auto&& v : adj[u]) {
        if (!visited[v]) {
            this->dfsUtil(v, visited);
        }
    }
}

void Graph::dfs(int u)
{
    bool* visited = new bool[this->v];
    for (int i = 0; i < this->v; i++)
        visited[i] = false;

    this->dfsUtil(u, visited);
};


int main(int argc, char* argv[])
{
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << "BFS: ";
    g.bfs(2);
    std::cout << "DFS: ";
    g.dfs(2);
    std::cout << "\n";

    return 0;
}
