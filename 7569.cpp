// BOJ #7569 -
// https://www.acmicpc.net/problem/7569
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, H;

    cin >> M >> N >> H;

    vector<vector<vector<int>>> board(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(N, vector<bool>(M, false)));
    queue<tuple<int, int, int, int>> q;

    int zero = 0;
    int day = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int num;
                cin >> num;
                board[i][j][k] = num;

                if (num == 0)
                {
                    zero++;
                }

                if (num == 1)
                {
                    q.push({j, k, i, 0});
                    visited[i][j][k] = true;
                }
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y, z, t] = q.front();
        q.pop();
        
        day = max(t, day);

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H)
            {
                if (!visited[nz][nx][ny] && board[nz][nx][ny] == 0)
                {
                    visited[nz][nx][ny] = true;
                    zero--;
                    q.push({nx, ny, nz, t + 1});
                }
            }
        }
    }

    if (zero > 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << day << endl;
    }

    return 0;
}
