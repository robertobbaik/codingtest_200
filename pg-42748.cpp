// 프로그래머스 - K번째수
// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    int num = commands.size();

    for(int i = 0; i < num; i++)
    {
        int start = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        
        vector<int> arr;
        for(int j = start - 1; j < end; j++)
        {
            arr.push_back(array[j]);
        }

        sort(arr.begin(), arr.end());

        answer.push_back(arr[target - 1]);

    }
    return answer;
}
