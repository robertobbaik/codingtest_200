// BOJ #2003 - 수들의 합 2
// https://www.acmicpc.net/problem/2003
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int sum = 0;
    int count = 0;

    for(int right = 0; right < N; right++)
    {
        sum += arr[right];

        while(sum >= M)
        {
            if(sum == M)
            {
                count++;
            }

            sum -= arr[left];
            left++;
        }
    }

    cout << count << endl;

    return 0;
}
