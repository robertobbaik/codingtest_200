// BOJ #1654 - 랜선 자르기
// https://www.acmicpc.net/problem/1654
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;

    cin >> K >> N;

    vector<int> arr(K);
    for(int i = 0; i < K; i++)
    {
        cin >> arr[i];
    }

    long long left = 1;
    long long right = *max_element(arr.begin(), arr.end());
    long long answer = 0;

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;

        for(int i = 0; i < K; i++)
        {
            count += arr[i] / mid;
        }

        if(count >= N)
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
