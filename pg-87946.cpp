// 프로그래머스 - 피로도
// https://school.programmers.co.kr/learn/courses/30/lessons/87946

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer = -1;

void backtracking(int k, vector<vector<int>> &dungeons, vector<bool> &visited, int depth)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && dungeons[i][0] <= k)
        {
            visited[i] = true;
            backtracking(k - dungeons[i][1], dungeons, visited, depth + 1);
            visited[i] = false;
        }
    }

    answer = max(depth, answer);
}

int solution(int k, vector<vector<int>> dungeons)
{
    vector<bool> visited(dungeons.size(), false);

    backtracking(k, dungeons, visited, 0);

    return answer;
}
