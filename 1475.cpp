// BOJ #1475 - 방 번호
// https://www.acmicpc.net/problem/1475

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(10);

    while(N)
    {
        arr[N % 10]++;
        N /= 10;
    }

    int six = arr[6];
    int nine = arr[9];

    arr[6] = (six + nine + 1) / 2;
    arr[9] = (six + nine + 1) / 2;

    int max_num = *max_element(arr.begin(), arr.end());

    cout << max_num << endl;


    return 0;
}
