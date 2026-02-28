// 프로그래머스 - 올바른 괄호
// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;

    for(char c : s)
    {
        if(c == '(')
        {
            st.push(c);
        }
        else
        {
            if(st.empty())
            {
                answer = false;
                break;
            }
            else
            {
                st.pop();
            }
        }
    }

    if(!st.empty())
    {
        answer = false;
    }
    
    return answer;
}
