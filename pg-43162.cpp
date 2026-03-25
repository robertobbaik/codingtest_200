// 프로그래머스 - 네트워크
// https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& computers, int n, vector<bool>& visited, int next)
{
    for(int i = 0; i < n; i++)
    {
        if(computers[next][i] == 1 && !visited[i])
        {
            visited[i] = true;
            dfs(computers, n, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            answer++;
            dfs(computers, n, visited, i);
        }
    }

    return answer;
}
