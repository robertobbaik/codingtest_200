// BOJ #1181 - 단어 정렬
// https://www.acmicpc.net/problem/1181
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool compare(const string &a, const string &b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }

    return a.length() < b.length();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    set<string> s;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    vector<string> arr(s.begin(), s.end());

    sort(arr.begin(), arr.end(), compare);

    for (string s : arr)
    {
        cout << s << '\n';
    }

    return 0;
}
