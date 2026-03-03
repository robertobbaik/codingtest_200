// BOJ #1436 - 영화감독 숌
// https://www.acmicpc.net/problem/1436
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;

    cin >> N;

    int answer = 1;
    int num = 666;
    while(answer < N)
    {
        num++;
        string temp = to_string(num);
        if(temp.find("666") != string::npos)
        {
            answer++;
        }
    }

    cout << num << endl;

    return 0;
}
