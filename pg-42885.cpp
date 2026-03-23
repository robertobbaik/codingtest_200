// 프로그래머스 - 구명보트
// https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    int left = 0;
    int right = people.size() - 1;

    sort(people.rbegin(), people.rend());

    while(left <= right)
    {
        if(people[left] + people[right] <= limit)
        {
            answer++;
            left++;
            right--;
        }
        else
        {
            answer++;
            left++;
        }
    }

    return answer;
}
