// BOJ #1916 - 최소비용 구하기
// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> distance(N + 1, INT_MAX);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while(!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if(distance[currentNode] < currentDistance)
        {
            continue;
        }

        for(auto [neighborNode, cost] : graph[currentNode])
        {
            int newDistance = distance[currentNode] + cost;

            if(newDistance < distance[neighborNode])
            {
                distance[neighborNode] = newDistance;
                pq.push({newDistance, neighborNode});
            }
        }
    }

    cout << distance[end] << endl;
    

    return 0;
}
