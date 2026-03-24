// BOJ #5014 - 스타트링크
// https://www.acmicpc.net/problem/5014
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int F, S, G, U, D;

    cin >> F >> S >> G >> U >> D;

    vector<bool> visited(F + 1, false);

    queue<pair<int, int>> q;

    q.push({S, 0});

    visited[S] = true;

    while (!q.empty())
    {
        auto [cur, count] = q.front();
        q.pop();

        if (cur == G)
        {
            cout << count << endl;
            return 0;
        }

        if (cur + U > 0 && cur + U < F + 1 && !visited[cur + U])
        {
            visited[cur + U] = true;
            q.push({cur + U, count + 1});
        }

        if (cur - D > 0 && cur - D < F + 1 && !visited[cur - D])
        {
            visited[cur - D] = true;
            q.push({cur - D, count + 1});
        }
    }

    cout << "use the stairs" << endl;

    return 0;
}
