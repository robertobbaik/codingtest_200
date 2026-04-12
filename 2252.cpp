// BOJ #2252 - 줄 세우기
// https://www.acmicpc.net/problem/2252

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);

    for(int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        graph[A].push_back(B);

        indegree[B]++;
    }

    queue<int> q;

    for(int i = 1; i < N + 1; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int num = q.front();
        q.pop();

        cout << num << ' ';

        for(int n : graph[num])
        {
            indegree[n]--;
            if(indegree[n] == 0)
            {
                q.push(n);
            }
        }
    }

    cout << '\n';

    return 0;
}
