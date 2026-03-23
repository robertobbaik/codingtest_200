// BOJ #1260 - DFS와 BFS
// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int next)
{
    cout << next << " ";

    for (int n : graph[next])
    {
        if (!visited[n])
        {
            visited[n] = true;
            dfs(graph, visited, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i = 1; i < N + 1; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    visited[V] = true;
    dfs(graph, visited, V);
    cout << endl;

    visited.assign(N + 1, false);

    queue<int> q;

    q.push(V);
    visited[V] = true;

    while (!q.empty())
    {
        int next = q.front();

        q.pop();

        cout << next << " ";

        for (int n : graph[next])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push(n);
            }
        }
    }

    return 0;
}
