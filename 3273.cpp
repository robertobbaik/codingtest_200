// BOJ #3273 - 두 수의 합
// https://www.acmicpc.net/problem/3273
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;
    int answer = 0;

    while(left < right)
    {
        if(arr[left] + arr[right] > x)
        {
            right--;
        }
        else if (arr[left] + arr[right] < x)
        {
            left++;
        }
        else
        {
            answer++;
            left++;
            right--;
        }
    }

    cout << answer << endl;

    return 0;
}
