// BOJ #20922 - 겹치는 건 싫어
// https://www.acmicpc.net/problem/20922
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

    vector<int> arr(N);
    vector<int> freq(1000001, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int answer = 0;
    for (int right = 0; right < N; right++)
    {
        freq[arr[right]]++;

        if (freq[arr[right]] > K)
        {
            while (freq[arr[right]] > K)
            {
                freq[arr[left]]--;
                left++;
            }
        }

        answer = max(answer, right - left + 1);
    }

    cout << answer << endl;

    return 0;
}
