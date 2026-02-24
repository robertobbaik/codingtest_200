// BOJ #10866 - 덱
// https://www.acmicpc.net/problem/10866
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    deque<int> dq;

    while (N--)
    {
        string command;
        cin >> command;

        if (command == "push_front")
        {
            int n;
            cin >> n;

            dq.push_front(n);
        }
        else if (command == "push_back")
        {
            int n;
            cin >> n;

            dq.push_back(n);
        }
        else if (command == "pop_front")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                int n = dq.front();
                dq.pop_front();
                cout << n << '\n';
            }
        }
        else if (command == "pop_back")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                int n = dq.back();
                dq.pop_back();
                cout << n << '\n';
            }
        }
        else if (command == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (command == "empty")
        {
            if (dq.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (command == "front")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << dq.front() << '\n';
            }
        }
        else if (command == "back")
        {
            if (dq.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}
