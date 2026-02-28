// BOJ #2231 - 분해합
// https://www.acmicpc.net/problem/2231
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int temp = i;
        int sum = 0;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum + i == N)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}
