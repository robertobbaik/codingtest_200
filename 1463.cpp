// BOJ #1463 - 1로 만들기
// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int visited[1000001] = {false, };

    visited[N] = true;

    queue<pair<int, int>> q;
    q.push({N, 0});

    while(!q.empty())
    {
        auto [num, count] = q.front();
        q.pop();


        if(num == 1)
        {
            cout << count << endl;
            return 0;
        }

        if(num % 3 == 0 && !visited[num / 3])
        {
            visited[num / 3] = true;
            q.push({num / 3, count + 1});
        }

        if(num % 2 == 0 && !visited[num / 2])
        {
            visited[num / 2] = true;
            q.push({num / 2, count + 1});
        }

        if(!visited[num - 1])
        {
            visited[num - 1] = true;
            q.push({num - 1, count + 1});
        }
    }

    return 0;
}
