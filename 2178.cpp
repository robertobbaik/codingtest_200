// BOJ #2178 - 미로 탐색
// https://www.acmicpc.net/problem/2178
#include <iostream>
#include <vector>
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
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }

    queue<tuple<int, int, int>> q;

    q.push({0, 0, 1});
    visited[0][0] = true;

    while (!q.empty())
    {
        tuple<int, int, int> t = q.front();
        q.pop();
        int x = get<0>(t);
        int y = get<1>(t);
        int count = get<2>(t);

        if(x == N - 1 && y == M - 1)
        {
            cout << count << endl;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if(board[nx][ny] == 1 && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, count + 1});
                }
            }
        }
    }

    return 0;
}
