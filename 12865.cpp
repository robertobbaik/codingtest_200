// BOJ #12865 - 평범한 배낭
// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    vector<int> W(N + 1);
    vector<int> V(N + 1);

    for (int i = 1; i < N + 1; i++)
    {
        int a, b;

        cin >> a >> b;

        W[i] = a;
        V[i] = b;
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 0; j < K + 1; j++)
        {
            if(j >= W[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}
