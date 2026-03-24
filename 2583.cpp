// BOJ #2583 - 영역 구하기
// https://www.acmicpc.net/problem/2583
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(vector<vector<bool>> &square, vector<vector<bool>> &visited, int M, int N, int x, int y, int& area)
{
    area++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            if(!square[nx][ny] && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                dfs(square, visited, M, N, nx, ny, area);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K;

    cin >> M >> N >> K;

    vector<vector<bool>> square(M, vector<bool>(N, false));
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    vector<int> answer;
    for (int i = 0; i < K; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int j = a; j < c; j++) 
        {
            for (int k = b; k < d; k++)
            {
                square[k][j] = true;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(!visited[i][j] && !square[i][j])
            {
                int area = 0;
                visited[i][j] = true;
                dfs(square, visited, M, N, i, j, area);
                answer.push_back(area);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for(int n : answer)
    {
        cout << n << " ";
    }

    return 0;
}
