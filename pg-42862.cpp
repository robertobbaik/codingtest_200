// 프로그래머스 - 체육복
// https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;

    vector<int> arr(n, 1);

    for (int n : lost)
    {
        arr[n - 1]--;
    }

    for (int n : reserve)
    {
        arr[n - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (i - 1 >= 0)
            {
                if (arr[i - 1] == 2)
                {
                    arr[i - 1]--;
                    arr[i]++;
                    continue;
                }
            }
            
            if (i < n - 1)
            {
                if(arr[i + 1] == 2)
                {
                    arr[i + 1]--;
                    arr[i]++;
                    
                }
            }
        }
    }

    for(int num : arr)
    {
        if(num == 0)
        {
            answer--;
        }
    }

    return answer;
}
