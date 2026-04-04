// BOJ #11279 - 최대 힙
// https://www.acmicpc.net/problem/11279
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}
