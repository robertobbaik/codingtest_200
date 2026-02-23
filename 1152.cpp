// BOJ #1152 - 단어의 개수
// https://www.acmicpc.net/problem/1152
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    int wordCount = 0;

    while(cin >> s)
    {
        wordCount++;
    }

    cout << wordCount;

    return 0;
}
