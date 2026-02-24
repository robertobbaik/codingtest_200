// BOJ #17298 - 오큰수
// https://www.acmicpc.net/problem/17298
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    stack<int> s;
    vector<int> answer(N, -1);
    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        while(!s.empty() && arr[s.top()] < arr[i])
        {
            answer[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int n : answer)
    {
        cout << n << " ";
    }

    return 0;
}
