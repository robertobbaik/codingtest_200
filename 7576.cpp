// BOJ #7576 - 토마토
// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<tuple<int, int, int>> q;
    int day = 0;
    int zero = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            board[i][j] = num;

            if (num == 0)
            {
                zero++;
            }

            if (num == 1)
            {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y, t] = q.front();
        q.pop();

        day = max(day, t);

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (!visited[nx][ny] && board[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    zero--;
                    q.push({nx, ny, t + 1});
                }
            }
        }
    }

    if(zero > 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << day << endl;
    }

    return 0;
}
