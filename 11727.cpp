// BOJ #11727 - 2×n 타일링 2
// https://www.acmicpc.net/problem/11727
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i < n + 1; i++)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }

    cout << dp[n] << endl;

    return 0;
}
