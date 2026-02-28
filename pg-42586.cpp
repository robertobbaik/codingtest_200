// 프로그래머스 - 기능개발
// https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    queue<int> q;

    for(int n : progresses)
    {
        q.push(n);
    }

    int day = 1;
    int index = 0;

    while(!q.empty())
    {
        int task = 0;
        int front = q.front();

        while(front + day * speeds[index] >= 100 && !q.empty())
        {
            task++;
            index++;
            q.pop();
            front = q.front();
        }

        if(task > 0)
        {
            answer.push_back(task);
        }
        day++;
    }

    return answer;
}
