// BOJ #1912 - 연속합
// https://www.acmicpc.net/problem/1912
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = -1001;

    dp[0] = arr[0];

    answer = dp[0];

    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;


    return 0;
}
