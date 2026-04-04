// BOJ #1920 - 수 찾기
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    unordered_set<int> us;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        us.insert(num);
    }

    int M;

    cin >> M;

    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        if(us.find(num) == us.end())
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }

    return 0;
}
