// BOJ #1541 - 잃어버린 괄호
// https://www.acmicpc.net/problem/1541
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimeter)
{
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimeter))
    {
        result.push_back(item);
    }

    return result;
}

int sum(string str)
{
    vector<string> v = split(str, '+');
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += stoi(v[i]);
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    vector<string> parts = split(str, '-');

    int result = sum(parts[0]);

    for (int i = 1; i < parts.size(); i++)
    {
        result -= sum(parts[i]);
    }

    cout << result << endl;

    return 0;
}
