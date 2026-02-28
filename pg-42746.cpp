// 프로그래머스 - 가장 큰 수
// https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> arr;

    for(int n : numbers)
    {
        arr.push_back(to_string(n));
    }

    sort(arr.begin(), arr.end(), compare);

    for(string s : arr)
    {
        answer += s;
    }

    if(answer[0] == '0') answer = "0";
    
    return answer;
}
