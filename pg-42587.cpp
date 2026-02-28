// 프로그래머스 - 프로세스
// https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int target = priorities[location];

    for(int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if(pq.top() == p.first)
        {
            pq.pop();
            answer++;
            if(p.second == location)
            {
                break;
            }
        }
        else
        {
            q.push(p);
        }
    }

    return answer;
}
