// BOJ #10816 - 숫자 카드 2
// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    unordered_map<int, int> um;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        um[num]++;
    }

    int M;

    cin >> M;

    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        if(um.find(num) != um.end())
        {
            cout << um[num] << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    return 0;
}
