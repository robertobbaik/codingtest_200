// BOJ #1026 - 보물
// https://www.acmicpc.net/problem/1026
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

    vector<int> a(N);
    vector<int> b(N);

    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int answer = 0;

    for(int i = 0; i < N; i++)
    {
        answer += a[i] * b[i];
    }

    cout << answer << endl;

    return 0;
}
 