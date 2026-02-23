// BOJ #1157 - 단어 공부
// https://www.acmicpc.net/problem/1157
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr(26, 0);

    string word;
    cin >> word;

    for (char c : word)
    {
        char nc = tolower(c);
        arr[nc - 97]++;
    }

    int max_num = *max_element(arr.begin(), arr.end());

    int biggest_count = 0;
    int max_idx = 0;

    for (int i = 0; i < 26; i++)
    {
        if (max_num == arr[i])
        {
            biggest_count++;
            max_idx = i;
        }
    }

    if (biggest_count == 1)
    {
        char c = max_idx + 97;

        cout << (char)toupper(c) << endl;
    }
    else
    {
        cout << '?' << endl;
    }

    return 0;
}
