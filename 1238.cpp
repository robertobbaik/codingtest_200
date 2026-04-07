// BOJ #1238 - 파티
// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dijkstra(int N, const vector<vector<pair<int, int>>>& graph, int start)
{
    vector<int> distance(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if(distance[currentNode] < currentDistance)
        {
            continue;
        }

        for(auto [neighorNode, cost] : graph[currentNode])
        {
            int newDistance = distance[currentNode] + cost;

            if(newDistance < distance[neighorNode])
            {
                distance[neighorNode] = newDistance;
                pq.push({newDistance, neighorNode});
            }
        }
    }

    return distance;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, X;

    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<pair<int, int>>> reverse_graph(N + 1);
    
    for (int i = 0; i < M; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        reverse_graph[v].push_back({u, w});
    }

    vector<int> dist_to_x = dijkstra(N, graph, X);
    vector<int> dist_from_x = dijkstra(N, reverse_graph, X);
    
    int max_distance = 0;

    for(int i = 1; i < N + 1; i++)
    {
        max_distance = max(max_distance, dist_from_x[i] + dist_to_x[i]);
    }

    cout << max_distance << endl;

    return 0;
}
