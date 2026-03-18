// BOJ #15650 - N과 M (2)
// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>
using namespace std;

// TODO

// 중복없이, 오름차순

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
        backtracking(N, M, arr, i + 1, depth + 1);
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
// 정확한 풀이. start로 오름차순 강제, i+1을 넘겨 중복 제거, 초기 start=1 모두 올바름
