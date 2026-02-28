// BOJ #2751 - 수 정렬하기 2
// https://www.acmicpc.net/problem/2751
#include <iostream>
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

    sort(arr.begin(), arr.end());

    for (int n : arr)
    {
        cout << n << '\n';
    }

    return 0;
}
