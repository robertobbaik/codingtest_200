// BOJ #15651 - N과 M (3)
// https://www.acmicpc.net/problem/15651
#include <iostream>
#include <vector>
using namespace std;

void backtracking(int N, int M, vector<int> &arr, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " \n"[i == M - 1];
        }
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        arr[depth] = i;
        backtracking(N, M, arr, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(8, 0);

    backtracking(N, M, arr, 0);
    return 0;
}
