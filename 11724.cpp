// BOJ #11724 - 연결 요소의 개수
// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int start)
{
    visited[start] = true;
    for(int next : graph[start])
    {
        if(!visited[next])
        {
            dfs(graph, visited, next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);

    int answer = 0;

    for(int i = 1; i < N + 1; i ++)
    {
        if(!visited[i])
        {
            answer++;
            dfs(graph, visited, i);
        }
    }

    cout << answer << endl;

    return 0;
}
