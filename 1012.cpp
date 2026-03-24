// BOJ #1012 - 유기농 배추
// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int M, int N, int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            if (!visited[nx][ny] && board[nx][ny] == 1)
            {
                dfs(board, visited, M, N, nx, ny);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int M, N;
        cin >> M >> N;

        vector<vector<int>> board(M, vector<int>(N, 0));
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        int K;
        cin >> K;

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;

            board[x][y] = 1;
        }

        int count = 0;

        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(!visited[i][j] && board[i][j] == 1)
                {
                    count++;
                    dfs(board, visited, M, N, i, j);
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
