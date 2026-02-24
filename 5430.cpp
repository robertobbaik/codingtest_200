// BOJ #5430 - AC
// https://www.acmicpc.net/problem/5430
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string command;
        cin >> command;

        int n;
        cin >> n;

        deque<int> dq;

        string s;
        cin >> s;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                temp += s[i];
            }
            else
            {
                if (!temp.empty())
                {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        }

        bool isReverse = false;
        bool isError = false;

        for (char cmd : command)
        {
            if (cmd == 'R')
            {
                isReverse = !isReverse;
            }
            else
            {
                if (dq.empty())
                {
                    isError = true;
                    break;
                }

                if (isReverse)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }
        }

        if (isError)
        {
            cout << "error\n";
        }
        else
        {
            cout << "[";
            if (isReverse)
            {
                reverse(dq.begin(), dq.end());
            }

            for (int i = 0; i < dq.size(); i++)
            {
                cout << dq[i];
                if(i < (int)dq.size() - 1) cout << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}
