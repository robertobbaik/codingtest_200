// BOJ #11399 - ATM
// https://www.acmicpc.net/problem/11399
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int answer = 0;

    for(int i = 1; i <= N; i++)
    {
        
        answer += accumulate(arr.begin(), arr.begin() + i, 0);
    }

    cout << answer << endl;

    return 0;
}
