// BOJ #2206 - 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    queue<tuple<int, int, int, int>> q;

    q.push({0, 0, 1, 1});
    visited[0][0][1] = true;

    while (!q.empty())
    {
        auto [x, y, time, destruct] = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << time << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
               if(board[nx][ny] == 0 && !visited[nx][ny][destruct])
               {
                    visited[nx][ny][destruct] = true;
                    q.push({nx, ny, time + 1, destruct});
               }
               else if(board[nx][ny] == 1 && destruct == 1 && !visited[nx][ny][0])
               {
                    visited[nx][ny][0] = true;
                    q.push({nx, ny, time + 1, 0});
               }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
