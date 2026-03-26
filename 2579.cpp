// BOJ #2579 - 계단 오르기
// https://www.acmicpc.net/problem/2579
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

    vector<int> stairs(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> stairs[i];
    }

    vector<int> dp(N + 1, 0);

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(dp[1] + stairs[3], stairs[2] + stairs[3]);

    for (int i = 4; i <= N; i++)
    {
        dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << dp[N] << endl;

    return 0;
}
