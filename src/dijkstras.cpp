#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.numVertices;
    vector<int> distances(G.numVertices, INF);
    previous.assign(G.numVertices, -1);
    vector<bool> visited(G.numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (const Edge& edge : G[u])
        {
            int v = edge.dst, weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination)
{
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& path, int total)
{
    for (size_t i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size()) cout << " ";
    }
    cout << "\nTotal cost is " << total << "\n";
}
