// BOJ #1717 - 집합의 표현
// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>

using namespace std;

int parent[1000001];

int find(int num)
{
    if (parent[num] != num)
    {
        parent[num] = find(parent[num]);
    }
    return parent[num];
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        parent[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n + 1; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int op, a, b;

        cin >> op >> a >> b;

        if (op == 0)
        {
            unite(a, b);
        }
        else
        {
            cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
