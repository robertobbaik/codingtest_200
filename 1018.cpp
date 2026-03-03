// BOJ #1018 - 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<string> &board, int startX, int startY, char startColor)
{
    int wrongCount = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char color = ((i + j) % 2 == 0) ? startColor : (startColor == 'W' ? 'B' : 'W');
            if (board[startX + i][startY + j] != color)
            {
                wrongCount++;
            }
        }
    }

    return wrongCount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<string> board(N);

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

	int startX = N - 7;
	int startY = M - 7;
	int minCount = 64;

	for (int i = 0; i < startX; i++)
	{
		for (int j = 0; j < startY; j++)
		{
			int wcount = check(board, i, j, 'W');
			int bcount = check(board, i, j, 'B');

			minCount = min({wcount, bcount, minCount});
		}
	}

	cout << minCount << endl;

    return 0;
}
