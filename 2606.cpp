// BOJ #2606 - 바이러스
// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int next)
{
    answer++;
    visited[next] = true;

    for(int n : graph[next])
    {
        if(!visited[n])
        {
            dfs(graph, visited, n);
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
    vector<bool> visited(N + 1, false);

    for(int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    dfs(graph, visited, 1);

    cout << answer - 1<< endl;

    return 0;
}
