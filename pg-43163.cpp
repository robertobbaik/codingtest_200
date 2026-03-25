// 프로그래머스 - 단어 변환
// https://school.programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int compare(const string& a, const string& b)
{
    int different = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
        {
            different++;
        }
    }

    return different;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    unordered_map<string, bool> visited;

    for(string str : words)
    {
        visited.insert({str, false});
    }

    queue<pair<string, int>> q;

    q.push({begin, 0});

    while(!q.empty())
    {
        auto [word, count] = q.front();
        q.pop();

        if(word == target)
        {
            answer = count;
        }

        for(auto& [next_word, isVisited] : visited)
        {
            if(!isVisited)
            {
                if(compare(word, next_word) == 1)
                {
                    isVisited = true;
                    q.push({next_word, count + 1});
                }
            }
        }
    }

    return answer;
}
