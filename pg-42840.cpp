// 프로그래머스 - 모의고사
// https://school.programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> temp(3, 0);

    for (int i = 0; i < answers.size(); i++)
    {
        if (a[i % a.size()] == answers[i])
        {
            temp[0]++;
        }

        if (b[i % b.size()] == answers[i])
        {
            temp[1]++;
        }

        if (c[i % c.size()] == answers[i])
        {
            temp[2]++;
        }
    }

    int max = *max_element(temp.begin(), temp.end());

    for(int i = 0; i < 3; i++)
    {
        if(max == temp[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

// [코드 평가]
// 정확한 풀이. 각 수포자의 패턴 길이로 순환(a.size(), b.size(), c.size()) 올바름
// max_element로 최고점 추출 후 동점자 모두 포함, 1-indexed 반환도 정확함

// [짚어볼 점]
// i < answers.size() 에서 int vs size_t 부호 불일치 — 컴파일러 경고 대상
//   → (int)answers.size() 또는 size_t i 로 맞추는 것이 엄밀함
// max는 표준 라이브러리 함수명과 충돌 가능 — max_val 등으로 바꾸는 것이 안전
