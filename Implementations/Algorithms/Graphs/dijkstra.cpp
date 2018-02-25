#include <algorithm>
#include <iostream>
#include <limits.h>
#include <list>
#include <utility>

class WeightedGraph {
private:
    int v;
    std::list<std::pair<int, int>>* adj;
    int minimumDistanceVertex(int*& dist, std::list<int>& spt);

public:
    WeightedGraph(int v);
    void addEdge(int u, std::pair<int, int> v);
    void dijkstra(int start);
};

WeightedGraph::WeightedGraph(int v)
{
    this->v = v;
    this->adj = new std::list<std::pair<int, int>>[v];
}

void WeightedGraph::addEdge(int u, std::pair<int, int> v)
{
    this->adj[u].push_back(v);
}

int WeightedGraph::minimumDistanceVertex(int*& dist, std::list<int>& spt)
{
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < this->v; i++) {
        if (std::find(spt.begin(), spt.end(), i) != spt.end() && dist[i] <= min) {
            min = dist[i];
            min_index = v;
        }
    }

    return min_index;
}

void WeightedGraph::dijkstra(int start)
{
    int* dist = new int[this->v];
    // shortest path tree
    std::list<int> spt;

    for (int i = 0; i < this->v; i++) {
        dist[i] = INT_MAX;
    }

    dist[start] = 0;

    for (int i = 0; i < v - 1; i++) {
        int u = minimumDistanceVertex(dist, spt);
        spt.push_back(u);

        for (int i = 0; i < this->v; i++) {
            for (auto&& p : adj[u]) {
                if (p.first == i) {
                    if (std::find(spt.begin(), spt.end(), i) != spt.end()
                        && dist[i] != INT_MAX && dist[u] + p.second < dist[i]) {
                        dist[i] = dist[u] + p.second;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < this->v; i++) {
        std::cout << i << "-" << dist[i] << std::endl;
    }
}

int main(int argc, char* argv[])
{
    return 0;
}
