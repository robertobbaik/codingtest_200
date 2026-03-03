// BOJ #15650 - N과 M (2)
// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int>& arr, int depth, int start, int N, int M)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = start; i <= N; i++)
    {
        arr[depth] = i;
        backtracking(arr, depth + 1, i + 1, N, M);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> arr(M);

    backtracking(arr, 0, 1, N, M);
    return 0;
}
