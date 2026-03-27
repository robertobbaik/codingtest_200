// BOJ #11055 - 가장 큰 증가하는 부분 수열
// https://www.acmicpc.net/problem/11055
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

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(N);

    //dp[0] = arr[0];

    for(int i = 0; i < N; i++)
    {
        dp[i] = arr[i];
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
