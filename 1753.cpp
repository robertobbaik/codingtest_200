// BOJ #1753 - 최단경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, start;

    cin >> V >> E >> start;

    vector<vector<pair<int, int>>> graph(V + 1);
    vector<int> distance(V + 1, INT_MAX);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (distance[currentNode] < currentDistance)
        {
            continue;
        }

        for (auto [neighborNode, cost] : graph[currentNode])
        {
            int newDistance = distance[currentNode] + cost;

            if (newDistance < distance[neighborNode])
            {
                distance[neighborNode] = newDistance;
                pq.push({newDistance, neighborNode});
            }
        }
    }

    for (int i = 1; i < V + 1; i++)
    {
        if (distance[i] == INT_MAX)
        {
            cout << "INF" << "\n";
        }
        else
        {
            cout << distance[i] << "\n";
        }
    }

    return 0;
}
