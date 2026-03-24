    // BOJ #1926 - 그림
    // https://www.acmicpc.net/problem/1926
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int N, int M, int x, int y, int &area)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (board[nx][ny] == 1 && !visited[nx][ny])
                {
                    area++;
                    visited[nx][ny] = true;
                    dfs(board, visited, N, M, nx, ny, area);
                }
            }
        }
    }

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
            for (int j = 0; j < M; j++)
            {
                cin >> board[i][j];
            }
        }

        vector<int> answer;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && board[i][j] == 1)
                {
                    int area = 1;
                    visited[i][j] = true;
                    dfs(board, visited, N, M, i, j, area);
                    answer.push_back(area);
                }
            }
        }

        cout << answer.size() << endl;

        if (answer.size() > 0)
        {
            int num = *max_element(answer.begin(), answer.end());
            cout << num << endl;
        }
        else
        {
            cout << 0 << endl;
        }

        return 0;
    }
