// BOJ #10844 - 쉬운 계단 수
// https://www.acmicpc.net/problem/10844
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

    vector<int> dp(N);

    //dp[0] = 1
    //dp[1] = 0, 2
    //dp[2] = 1, 3
    //dp[3] = 0,1,2,4
    //dp[4] = 0,1,2,3,5
    return 0;
}
