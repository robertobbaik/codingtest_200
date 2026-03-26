// BOJ #9095 - 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<int> dp(12);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    for (int i = 5; i < 12; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    while (T--)
    {
        int n;
        cin >> n;

        cout << dp[n] << endl;
    }

    return 0;
}
