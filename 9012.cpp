// BOJ #9012 - 괄호
// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string ps;
        cin >> ps;

        stack<char> s;

        bool is_completed = false;
        for (char c : ps)
        {
            if (c == '(')
            {
                s.push(c);
            }
            else
            {
                if (!s.empty())
                {
                    s.pop();
                }
                else
                {
                    cout << "NO" << endl;
                    is_completed = true;
                    break;
                }
            }
        }

        if (is_completed) continue;

        if (s.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
