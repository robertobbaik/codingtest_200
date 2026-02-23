// BOJ #10871 - X보다 작은 수
// https://www.acmicpc.net/problem/10871
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    cin >> N >> X;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if(num < X)
        {
            cout << num << " ";
        }
    }



    return 0;
}
