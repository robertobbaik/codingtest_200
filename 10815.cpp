// BOJ #10815 - 숫자 카드
// https://www.acmicpc.net/problem/10815
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    unordered_set<int> us;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        us.insert(num);
    }

    int M;
    cin >> M;

    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        if(us.find(num) != us.end())
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    return 0;
}
