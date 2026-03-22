// BOJ #1715 - 카드 정렬하기
// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        pq.push(num);
    }

    long long answer = 0;

    while (pq.size() > 1)
    {
        long long num1 = pq.top();
        pq.pop();
        long long num2 = pq.top();
        pq.pop();

        long long temp = num1 + num2;
        answer += temp;

        pq.push(temp);
    }

    cout << answer << endl;
}
