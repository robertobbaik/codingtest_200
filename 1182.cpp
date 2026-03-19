// BOJ #1182 - 부분수열의 합
// https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void backtracking(int N, int S, vector<int> &arr, int index, int sum, int depth)
{
    if (index == N)
    {
        if (sum == S && depth > 0)
        {
            answer++;
        }
        return;
    }

    backtracking(N, S, arr, index + 1, sum + arr[index], depth + 1);
    backtracking(N, S, arr, index + 1, sum, depth);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    backtracking(N, S, arr, 0, 0, 0);

    cout << answer << endl;

    return 0;
}

// [코드 평가]
// depth 파라미터로 공집합 제외 — S값에 의존하지 않아 범용적, 단일 호출로 명확함

// [짚어볼 점]
// "두 번 호출 분리"로 공집합 제거가 안 되는 이유:
//   backtracking(N, S, arr, 1, 0)에서 arr[1..N-1] 전부 제외 선택 시
//   sum=0 리프가 여전히 생성됨 → S=0이면 카운트됨
// depth > 0 대신 비트마스크 풀이(i=1부터 시작)도 동일 원리로 공집합 제외
