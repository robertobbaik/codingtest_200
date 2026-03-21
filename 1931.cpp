// BOJ #1931 - 회의실 배정
// https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector<pair<int, int>> vp;

    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        pair<int, int> p = {a, b};

        vp.push_back(p);
    }

    sort(vp.begin(), vp.end(), compare);

    int end = vp[0].second;
    int count = 1;

    for(int i = 1; i < N; i++)
    {
        if(vp[i].first >= end)
        {
            end = vp[i].second;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
