// BOJ #15652 - N과 M (4)
// https://www.acmicpc.net/problem/15652
#include <iostream>
#include <vector>
using namespace std;

// TODO
void backtracking(int N, int M, vector<int> &arr, int start, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " \n"[i == M - 1];
        }
        return;
    }

    for (int i = start; i <= N; i++)
    {
        arr[depth] = i;
        backtracking(N, M, arr, i, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // TODO
    vector<int> arr(8, 0);
    backtracking(N, M, arr, 1, 0);

    return 0;
}

// [코드 평가]
// 거의 정확. 중복 허용을 위해 i+1 대신 i를 넘기는 방향이 맞음
// backtracking(..., i, ...) → 같은 숫자 다시 선택 가능, 비내림차순 보장
