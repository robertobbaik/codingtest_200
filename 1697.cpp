// BOJ #1697 -
// https://www.acmicpc.net/problem/1697
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N >> K;

    queue<pair<int, int>> q;
    bool visited[100001] = {false,};
    q.push({N, 0});
    visited[N] = true;
    

    while(!q.empty())
    {
        auto[pos, time] = q.front();
        q.pop();

        if(pos == K)
        {
            cout << time << endl;
            break;
        }

        if(pos - 1 >= 0 && pos - 1 < 100001 && !visited[pos -1])
        {
            visited[pos - 1] = true;
            q.push({pos - 1, time + 1});
        }

        if(pos + 1 >= 0 && pos + 1 < 100001 && !visited[pos + 1])
        {
            visited[pos + 1] = true;
            q.push({pos + 1, time + 1});
        }

        if(pos * 2 >= 0 && pos * 2 < 100001 && !visited[pos * 2])
        {
            visited[pos * 2] = true;
            q.push({pos * 2, time + 1});
        }
    }



    return 0;
}
