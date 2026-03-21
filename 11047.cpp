// BOJ #11047 - 동전 0
// https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N >> K;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int count = 0;
    int index = N - 1;

    while (sum < K)
    {
        if (sum + arr[index] < K)
        {
            sum += arr[index];
            count++;
        }
        else if (sum + arr[index] > K)
        {
            index--;
            if(index < 0)
            {
                cout << 0 << endl;
                break;
            }
        }
        else if(sum + arr[index] == K)
        {
            count++;
            cout << count << endl;
            break;
        }
    }

    return 0;
}
