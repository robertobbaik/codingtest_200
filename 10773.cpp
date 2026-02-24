// BOJ #10773 - 제로
// https://www.acmicpc.net/problem/10773
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    vector<int> arr;

    for(int i = 0; i < K; i++)
    {
        int n;
        cin >> n;

        if(n == 0)
        {
            arr.pop_back();
        }
        else
        {
            arr.push_back(n);
        }
    }

    int sum = accumulate(arr.begin(), arr.end(), 0);

    cout << sum << endl;


    return 0;
}
