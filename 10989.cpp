// BOJ #10989 - 수 정렬하기 3
// https://www.acmicpc.net/problem/10989

#include <iostream>
#include <algorithm>
using namespace std;

int count_arr[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        count_arr[num]++;
    }

    for(int i = 1; i <= 10000; i++)
    {
        while(count_arr[i] > 0)
        {
            cout << i << '\n';
            count_arr[i]--;
        }
    }

    return 0;
}
