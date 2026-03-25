// BOJ #2468 - 안전 영역
// https://www.acmicpc.net/problem/2468
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int N, int limit, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            if (!visited[nx][ny] && board[nx][ny] > limit)
            {
                visited[nx][ny] = true;
                dfs(board, visited, N, limit, nx, ny);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    int max_num = 0;
    int min_num = 101;
    int answer = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            board[i][j] = num;

            max_num = max(num, max_num);
            min_num = min(num, min_num);
        }
    }

    for (int i = min_num; i <= max_num; i++)
    {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        int area = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (!visited[j][k] && board[j][k] > i)
                {
                    area++;
                    visited[j][k] = true;
                    dfs(board, visited, N, i, j, k);
                    answer = max(area, answer);
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
