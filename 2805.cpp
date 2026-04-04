// BOJ #2805 - 나무 자르기
// https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long long left = 1;
    long long right = *max_element(arr.begin(), arr.end());
    long long answer = 0;

    while (left <= right)
    {
        long long len = 0;
        long long mid = (left + right) / 2;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] > mid)
            {
                len += arr[i] - mid;
            }
        }

        if (len >= M)
        {
            answer = mid;
            left = mid + 1;
            
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
