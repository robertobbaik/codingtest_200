// BOJ #15649 - N과 M (1)
// https://www.acmicpc.net/problem/15649
#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int>& arr, vector<bool>& used, int depth, int N, int M)
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

    for(int i = 1; i <= N; i++)
    {
        if(!used[i])
        {
            used[i] = true;
            arr[depth] = i;
            backtracking(arr, used, depth + 1, N, M);
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

    vector<int> arr(N);
    vector<bool> used(N + 1, false);

    backtracking(arr, used, 0, N, M);

    return 0;
}
