// BOJ #2562 - 최댓값
// https://www.acmicpc.net/problem/2562
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr(9);

    for(int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    int maxnum = *max_element(arr.begin(), arr.end());
    cout << maxnum << endl;
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] == maxnum)
        {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
