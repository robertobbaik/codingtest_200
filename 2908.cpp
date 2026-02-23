// BOJ #2908 - 상수
// https://www.acmicpc.net/problem/2908
#include <iostream>
#include <algorithm>

using namespace std;

int reverse(int num)
{
    int reverse_num = 0;
    int amount = 100;
    while(num)
    {
        reverse_num += (num % 10) * amount;
        num /= 10;
        amount /= 10;
    }

    return reverse_num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;

    cin >> A >> B;

    cout << max(reverse(A), reverse(B)) << endl;

    
    return 0;
}
