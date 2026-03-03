// BOJ #7568 - 덩치
// https://www.acmicpc.net/problem/7568
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> arr(N);
    vector<int> answer(N);

    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        arr[i] = {x, y};
    }

    for(int i = 0; i < N; i++)
    {
        int rank = 1;
        for(int j = 0; j < N; j++)
        {
            if(i == j) continue;
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second)
            {
                rank++;
            }
        }

        answer[i] = rank;
    }

    for(int n : answer)
    {
        cout << n << ' ';
    }




    return 0;
}
