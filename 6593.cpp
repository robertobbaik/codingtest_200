// BOJ #6593 - 상범 빌딩
// https://www.acmicpc.net/problem/6593
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int L, R, C;

        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0)
        {
            break;
        }

        vector<vector<vector<char>>> building(L, vector<vector<char>>(R, vector<char>(C)));
        vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(R, vector<bool>(C, false)));

        queue<tuple<int, int, int, int>> q;

        bool isEscaped = false;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                string str;
                cin >> str;
                for (int k = 0; k < C; k++)
                {
                    building[i][j][k] = str[k];
                    if (str[k] == 'S')
                    {
                        q.push({i, j, k, 0});
                        visited[i][j][k] = true;
                    }
                }
            }
        }

        while (!q.empty())
        {
            auto [floor, row, col, time] = q.front();
            q.pop();

            if (building[floor][row][col] == 'E')
            {
                cout << "Escaped in " << time << " minute(s)." << endl;

                isEscaped = true;
                break;
            }

            for (int i = 0; i < 6; i++)
            {
                int nf = floor + dx[i];
                int nr = row + dy[i];
                int nc = col + dz[i];

                if (nf >= 0 && nf < L && nr >= 0 && nr < R && nc >= 0 && nc < C)
                {
                    if (building[nf][nr][nc] != '#' && !visited[nf][nr][nc])
                    {
                        visited[nf][nr][nc] = true;
                        q.push({nf, nr, nc, time + 1});
                    }
                }
            }
        }

        if (!isEscaped)
        {
            cout << "Trapped!" << endl;
        }
    }

    return 0;
}
