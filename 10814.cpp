// BOJ #10814 - 나이순 정렬
// https://www.acmicpc.net/problem/10814
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<pair<int, string>> arr;

    for(int i = 0; i < N; i++)
    {
        int age;
        cin >> age;
        string name;
        cin >> name;

        arr.push_back({age, name});
    }

    stable_sort(arr.begin(), arr.end(), compare);

    for(auto& p : arr)
    {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
