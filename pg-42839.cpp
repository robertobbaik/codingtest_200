// 프로그래머스 - 소수 찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int answer = 0;

bool isValid(int num)
{
    if (num < 2)
    {
        return false;
    }

    if (num == 2)
    {
        return true;
    }

    if (num % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(string numbers)
{
    int answer = 0;

    set<int> s;

    sort(numbers.begin(), numbers.end());

    do
    {
        string temp;
        for (char c : numbers)
        {
            temp += c;
            int num = stoi(temp);
            s.insert(num);
        }
        temp = "";
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (int n : s)
    {
        if (isValid(n))
        {
            answer++;
        }
    }

    return answer;
}
