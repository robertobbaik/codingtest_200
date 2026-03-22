// 프로그래머스 - 체육복
// https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n - lost.size();

    vector<int> arr(n, 1);

    for (int n : lost)
    {
        arr[n - 1]--;
    }

    for (int n : reserve)
    {
        arr[n - 1]++;
    } 

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            if(i - 1 <= 0)
            {
                
            }
        }
    }

    return answer;
}
