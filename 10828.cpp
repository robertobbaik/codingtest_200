// BOJ #10828 - 스택
// https://www.acmicpc.net/problem/10828
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<int> s;

    while (N--)
    {
        string command;
        cin >> command;

        if(command == "push")
        {
            int n;
            cin >> n;
            s.push(n);
        }
        if(command == "top")
        {
            if(s.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << s.top() << endl;
            }
        }
        if(command == "size")
        {
            cout << s.size() << endl;
        }

        if(command == "empty")
        {
            if(!s.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }

        if(command == "pop")
        {
            if(!s.empty())
            {
                cout << s.top() << endl;
                s.pop();
            }
            else
            {
                cout << -1 << endl;
            }
        }

    }

    return 0;
}
