// 프로그래머스 - 카펫
// https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int total = brown + yellow;

    int minVal = 2;

    for(int i = minVal; i < total / minVal; i++)
    {
        if(total % i == 0)
        {
            int w = total / i;
            int tempBrown = 2 * w + 2 * (i - 2);

            if(tempBrown == brown)
            {
                answer.push_back(total / i);
                answer.push_back(i);
                break;
            }
        }
    }

    return answer;
}

// [코드 평가]
// 정확한 풀이. total의 약수를 순회하며 brown 공식으로 검증, break으로 첫 해에서 종료
// 2*(i-2) = 2*i-4 이므로 테두리 공식 brown = 2*w + 2*(h-2) 올바름

// [짚어볼 점]
// i < total / minVal 대신 i <= sqrt(total)이 더 명시적 — 의도가 "약수 쌍 탐색"임을 드러냄
// minVal=2 상수는 카펫 최소 높이(3)를 고려하면 i=3 시작이 더 엄밀하나 결과는 동일
