// BOJ #2798 - 블랙잭
// https://www.acmicpc.net/problem/2798
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            for(int k = j + 1; k < N; k++)
            {
                int a = arr[i];
                int b = arr[j];
                int c = arr[k];

                if(a + b + c <= M)
                {
                    answer = max(answer, a + b + c);
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
