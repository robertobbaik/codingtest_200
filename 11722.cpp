// BOJ #11722 - 가장 긴 감소하는 부분 수열
// https://www.acmicpc.net/problem/11722
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

    vector<int> arr(N, 0);
    vector<int> dp(N, 0);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
