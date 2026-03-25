// 프로그래머스 - 게임 맵 최단거리
// https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int solution(vector<vector<int>> maps)
{
    int answer = -1;

    int n = maps.size();
    int m = maps[0].size();

    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({0, 0, 1});
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [x, y, t] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            answer = t;
            return answer;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if(!visited[nx][ny] && maps[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, t + 1});
                }
            }
        }
    }

    return answer;
}
