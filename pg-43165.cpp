// 프로그래머스 - 타겟 넘버
// https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    queue<pair<int, int>> q;

    q.push({0, 0});

    while(!q.empty())
    {
        auto [num, depth] = q.front();
        q.pop();

        if(depth == numbers.size())
        {
            if(num == target)
            {
                answer++;
            }
            continue;
        }

        q.push({num + numbers[depth], depth + 1});
        q.push({num - numbers[depth], depth + 1});
    }

    return answer;
}
