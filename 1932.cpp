// BOJ #1932 - 정수 삼각형
// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int num;
    int leftNum;
    int rightNum;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int num;
            cin >> num;
            graph[i].push_back(num);
        }
    }

    vector<vector<int>> dp(graph.begin(), graph.end());

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + graph[i][j];
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + graph[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1] + graph[i][j], dp[i - 1][j] + graph[i][j]);
            }
        }
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;

    return 0;
}
