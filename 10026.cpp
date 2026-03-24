// BOJ #10026 - 적록색약
// https://www.acmicpc.net/problem/10026
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<string> &board, vector<vector<bool>> &visited, int N, int M, int x, int y, char ch)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (board[nx][ny] == ch && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                dfs(board, visited, N, M, nx, ny, ch);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> board;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }

    int r = 0;
    int b = 0;
    int g = 0;
    int M = board[0].size();
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
            {
                int area = 0;
                visited[i][j] = true;
                if (board[i][j] == 'R')
                    r++;
                if (board[i][j] == 'B')
                    b++;
                if (board[i][j] == 'G')
                    g++;
                
                dfs(board, visited, N, M, i, j, board[i][j]);
            }
        }
    }
    cout << r + g + b << " ";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'G')
            {
                board[i][j] = 'R';
            }
        }
    }

    visited.assign(N, vector<bool>(M, false));
    r = 0;
    b = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                if (board[i][j] == 'R')
                    r++;
                if (board[i][j] == 'B')
                    b++;
                dfs(board, visited, N, M, i, j, board[i][j]);
            }
        }
    }

    cout << r + b << endl;

    return 0;
}
