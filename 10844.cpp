// BOJ #10844 - 쉬운 계단 수
// https://www.acmicpc.net/problem/10844
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i < N + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
            }
        }
    }

    cout << accumulate(dp[N].begin(), dp[N].end(), 0LL) % 1000000000 << endl;

    return 0;
}
