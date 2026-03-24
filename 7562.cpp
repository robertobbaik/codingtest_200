// BOJ #7562 - 나이트의 이동
// https://www.acmicpc.net/problem/7562
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        int l;
        cin >> l;

        pair<int, int> currentPos;
        cin >> currentPos.first >> currentPos.second;

        pair<int, int> targetPos;
        cin >> targetPos.first >> targetPos.second;

        vector<vector<bool>> visited(l, vector<bool>(l, false));
        queue<tuple<int, int, int>> q;
        q.push({currentPos.first, currentPos.second, 0});
        visited[currentPos.first][currentPos.second] = true;

        while(!q.empty())
        {
            auto [x, y, t] = q.front();
            q.pop();

            if(x == targetPos.first && y == targetPos.second)
            {
                cout << t << endl;
                break;
            }

            for(int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < l && ny >= 0 && ny < l)
                {
                    if(!visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny, t + 1});
                    }
                }
            }
        }
    }

    return 0;
}
