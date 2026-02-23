// BOJ #10818 - 최소, 최대
// https://www.acmicpc.net/problem/10818
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int maxnum = -1000001;
    int minnum = 1000001;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        maxnum = max(maxnum, num);
        minnum = min(minnum, num);
    }

    cout << minnum << " " << maxnum << endl;
    return 0;
}
