// BOJ #1806 - 부분합
// https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;

    cin >> N >> S;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    
    int sum = 0;
    int answer = N + 1;
    
    for(int right = 0; right < N; right++)
    {
        sum += arr[right];

        while(sum >= S)
        {
            answer = min(answer, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    cout << ((answer == N + 1) ? 0 : answer) << endl;

    return 0;
}
