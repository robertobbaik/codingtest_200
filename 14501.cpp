// BOJ #14501 - 퇴사
// https://www.acmicpc.net/problem/14501
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

    vector<int> T(N + 1);
    vector<int> P(N + 1);

    vector<int> dp(N + 2, 0);

    dp[N] = 0;

    for (int i = 1; i < N + 1; i++)
    {
        int a, b;

        cin >> a >> b;

        T[i] = a;
        P[i] = b;
    }

    for(int i = N; i > 0; i--)
    {
        if(i + T[i] - 1 <= N)
        {
            dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << endl;

    return 0;
}
