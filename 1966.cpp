// BOJ #1966 - 프린터 큐
// https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;

        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i = 0; i < N; i++)
        {
            int importance;
            cin >> importance;

            q.push({i, importance});
            pq.push(importance);
        }

        int count = 0;

        while(!q.empty())
        {
            int idx = q.front().first;
            int imp = q.front().second;

            q.pop();

            if(imp == pq.top())
            {
                pq.pop();
                count++;

                if(idx == M)
                {
                    cout << count << '\n';
                    break;
                }
            }
            else
            {
                q.push({idx, imp});
            }
        }
    }

    return 0;
}
