// BOJ #2217 - 로프
// https://www.acmicpc.net/problem/2217
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

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    int max_wegiht = 0;

    for (int i = 0; i < N; i++)
    {
        max_wegiht = max(max_wegiht, arr[i] * (i + 1));
    }

    cout << max_wegiht << endl;

    return 0;
}
