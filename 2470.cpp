// BOJ #2470 - 두 용액
// https://www.acmicpc.net/problem/2470
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = N - 1;
    int answer = INT_MAX;
    int answer_l = 0;
    int answer_r = 0;

    while (left < right)
    {
        int num = arr[left] + arr[right];
        int gap = abs(num);

        if (gap < answer)
        {
            answer = gap;
            answer_l = arr[left];
            answer_r = arr[right];
        }

        if(num < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << answer_l << " " << answer_r << endl;

    return 0;
}
