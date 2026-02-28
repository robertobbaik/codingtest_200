// 프로그래머스 - 주식가격
// https://school.programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            int top = s.top();
            s.pop();
            answer[top] = i - top;
        }
        s.push(i);
    }

    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        answer[top] = n - 1 - top;
    }

    return answer;
}
