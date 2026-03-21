// BOJ #13305 - 주유소
// https://www.acmicpc.net/problem/13305
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

    vector<long long> distance(N);
    vector<long long> price(N);

    for (int i = 1; i < N; i++)
    {
        cin >> distance[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
    }

    long long min_price = price[0];
    long long cost = 0;

    for (int i = 1; i < N; i++)
    {
        min_price = min(price[i - 1], min_price);
        cost += (distance[i] * min_price);
    }

    cout << cost << endl;

    return 0;
}
