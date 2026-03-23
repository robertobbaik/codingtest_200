// 프로그래머스 - 큰 수 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
#include <stack>

using namespace std;


string solution(string number, int k)
{
    string answer = "";
    int len = number.size();
    stack<char> s;

    for(char c : number)
    {
        while(!s.empty() && s.top() < c && k > 0)
        {
            s.pop();
            k--;
        }
        s.push(c);
    }

    while(k > 0)
    {
        s.pop();
        k--;
    }

    while(!s.empty())
    {
        answer = s.top() + answer;
        s.pop();
    }
    

    return answer;
}