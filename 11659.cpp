// BOJ #11659 - 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N + 1, 0);
    vector<int> dp(N + 1, 0);
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i];
    }

    while(M--)
    {
        int a, b;

        cin >> a >> b;

        cout << dp[b] - dp[a - 1] << "\n";
    }

    return 0;
}
