// BOJ #2667 - 단지번호붙이기
// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int N, int x, int y, int &count)
{
    count++;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!visited[nx][ny] && board[nx][ny] == 1)
            {

                dfs(board, visited, N, nx, ny, count);
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
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        string str;

        cin >> str;
        for (int j = 0; j < N; j++)
        {
            char c = str[j];

            int num = c == '0' ? 0 : 1;
            board[i][j] = num;
        }
    }

    vector<int> answer;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
            {
                int temp = 0;
                dfs(board, visited, N, i, j, temp);
                if (temp > 0)
                {
                    answer.push_back(temp);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for (int n : answer)
    {
        cout << n << '\n';
    }

    return 0;
}
