// 프로그래머스 - 더 맵게
// https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    while (pq.size() >= 2 && pq.top() < K)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        pq.push(a + (b * 2));

        answer++;
    }

    if(pq.top() >= K)
    {
        return answer;
    }
    else
    {
        return -1;
    }

    return -1;
}
