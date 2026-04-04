// BOJ #9251 - LCS
// https://www.acmicpc.net/problem/9251
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;

    cin >> A >> B;

    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[A.size()][B.size()] << endl;

    return 0;
}
