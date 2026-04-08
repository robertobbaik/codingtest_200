// BOJ #1197 - 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;

    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++)
    {
        int A, B, C;

        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    vector<bool> visited(V + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});

    long long answer = 0;

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (visited[currentNode])
        {
            continue;
        }

        visited[currentNode] = true;
        answer += currentDistance;

        for (auto [neigborNode, cost] : graph[currentNode])
        {
            if(!visited[neigborNode])
            {
                pq.push({cost, neigborNode});
            }
        }
    }

    cout << answer << endl;

    return 0;
}
