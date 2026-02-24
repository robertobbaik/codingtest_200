// BOJ #2164 - 카드2
// https://www.acmicpc.net/problem/2164
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    deque<int> dq(N);

    for (int i = 0; i < N; i++)
    {
        dq[i] = i + 1;
    }

    while (dq.size() > 1)
    {
        dq.pop_front();
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }

    cout << dq[0] << endl;

    return 0;
}
