// BOJ #2110 - 공유기 설치
// https://www.acmicpc.net/problem/2110
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;
    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 1; // 1
    int right = arr[N - 1] - arr[0]; // 8
    int mindis = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2; // 4
        
        int count = 1;
        int last = arr[0];

        for (int i = 1; i < N; i++)
        {
            if (arr[i] - last >= mid)
            {
                count++;
                last = arr[i];
            }
        }

        if (count >= C)
        {
            mindis = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << mindis << endl;

    return 0;
}
