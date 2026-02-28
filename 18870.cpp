// BOJ #18870 - 좌표 압축
// https://www.acmicpc.net/problem/18870
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

    vector<int> arr(N);
    vector<int> sorted_arr(N);

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }

    sort(sorted_arr.begin(), sorted_arr.end());

    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    for(int n : arr)
    {
        auto it = lower_bound(sorted_arr.begin(), sorted_arr.end(), n);

        cout << it - sorted_arr.begin() << " ";
    }

    return 0;
}
