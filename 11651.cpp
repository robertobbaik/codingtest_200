// BOJ #11651 - 좌표 정렬하기 2
// https://www.acmicpc.net/problem/11651
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
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
        int x, y;
        cin >> x >> y;

        vp.push_back({x, y});
    }

    sort(vp.begin(), vp.end(), compare);

    for(auto& p : vp)
    {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
