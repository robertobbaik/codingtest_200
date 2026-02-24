// BOJ #1021 - 회전하는 큐
// https://www.acmicpc.net/problem/1021
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    deque<int> dq;
    for (int i = 0; i < N; i++)
    {
        dq.push_back(i + 1);
    }

    int count = 0;

    vector<int> targets(M);
    while (M--)
    {
        int target;
        cin >> target;

        int idx = 0;

        auto it = find(dq.begin(), dq.end(), target);
        
        
    }

    return 0;
}
