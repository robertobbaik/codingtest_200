// BOJ #11404 - 플로이드
// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int m;
    cin >> m;

    const int INF = 1e9;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < n + 1; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 0; k < n + 1; k++)
    {
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (dist[i][j] == INF ? 0 : dist[i][j]);
            if (j < n)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
