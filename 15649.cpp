// BOJ #15649 - N과 M (1)
// https://www.acmicpc.net/problem/15649
#include <iostream>
#include <vector>

using namespace std;

// TODO
// 중복없이 수열 상관없음
void backtracking(int N, int M, vector<int> &arr, vector<bool> &used, int depth)
{
    if (M == depth)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " \n"[i == M - 1];
        }
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        if(!used[i])
        {
            arr[depth] = i;
            used[i] = true;
            backtracking(N, M, arr, used, depth + 1);
            used[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(8, 0);
    vector<bool> used(8, false);
    backtracking(N, M, arr, used, 0);
    // TODO

    return 0;
}
