#include <iostream>
#include <list>
#include <stack>

using namespace std;

template <typename T>
class Graph {
private:
    int v;
    list<T>* adj;

    void topologicalSortUtil(int, bool*&, stack<T>&);

public:
    Graph(int v);
    void addEdge(int u, int v);
    void topologicalSort();
};

template <typename T>
Graph<T>::Graph(int v)
{
    this->v = v;
    this->adj = new list<T>[v];
}

template <typename T>
void Graph<T>::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

template <typename T>
void Graph<T>::topologicalSortUtil(int v, bool*& visited, stack<T>& stack)
{
    visited[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            topologicalSortUtil(*it, visited, stack);
        }
    }

    stack.push(v);
}

template <typename T>
void Graph<T>::topologicalSort()
{
    stack<T> stack;

    bool* visited = new bool[this->v];

    for (int i = 0; i < this->v; i++)
        visited[i] = false;

    for (int i = 0; i < this->v; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack);
        }
    }

    while (stack.empty() == false) {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main(int argc, char* argv[])
{
    Graph<int> g(6);
    g.addEdge(5, 2);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(5, 0);

    g.topologicalSort();
    cout << "\n";

    return 0;
}
