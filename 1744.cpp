// BOJ #1744 - 수 묶기
// https://www.acmicpc.net/problem/1744
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> pos;
    vector<int> neg;

    int zeros = 0;
    int one = 0;

    long long answer = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num > 1)
        {
            pos.push_back(num);
        }
        else if (num < 0)
        {
            neg.push_back(num);
        }
        else if (num == 1)
        {
            one++;
        }
        else if (num == 0)
        {
            zeros++;
        }
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    for (int i = 0; i + 1 < pos.size(); i += 2)
    {
        answer += pos[i] * pos[i + 1];
    }

    if (pos.size() % 2 == 1)
    {
        answer += pos.back();
    }

    for (int i = 0; i + 1 < neg.size(); i += 2)
    {
        answer += neg[i] * neg[i + 1];
    }

    if (neg.size() % 2 == 1)
    {
        if (zeros < 1)
        {
            answer += neg.back();
        }
    }

    answer += one;

    cout << answer << endl;

    return 0;
}
