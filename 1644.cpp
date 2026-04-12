// BOJ #1644 - 소수의 연속합
// https://www.acmicpc.net/problem/1644
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // TODO(human): 에라토스테네스의 체로 소수 배열 arr 채우기
    // vector<bool> sieve(N+1, true) 로 시작
    // sieve[0] = sieve[1] = false
    // i=2부터 i*i<=N 동안: sieve[i]가 true면 i의 배수들을 false로
    // 마지막에 sieve[i]==true인 i를 arr에 push_back

    vector<bool> sieve(N + 1, true);

    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    vector<int> arr;

    for(int i = 0; i < N + 1; i++)
    {
        if(sieve[i])
        {
            arr.push_back(i);
        }
    }

    int left = 0;
    int sum = 0;
    int count = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        sum += arr[right];

        while (sum >= N)
        {
            if (sum == N)
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
