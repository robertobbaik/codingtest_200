// BOJ #2493 - 탑
// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<pair<int, int>> s;

    for(int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;

        while(!s.empty())
        {
            if(s.top().first > height)
            {
                cout << s.top(). second << " ";
                break;
            }

            s.pop();
        }

        if(s.empty())
        {
            cout << 0 << " ";
        }

        s.push({height, i});
    }

    return 0;
}
