// BOJ #9663 - N-Queen
// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>

using namespace std;

int total;

bool isValid(int N, vector<vector<bool>> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

void backtracking(int N, int row, vector<vector<bool>> &board)
{
    if (row == N)
    {
        total++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isValid(N, board, row, i))
        {
            board[row][i] = true;
            backtracking(N, row + 1, board);
            board[row][i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<bool>> board(N, vector<bool>(N, false));

    backtracking(N, 0, board);
    cout << total << endl;

    return 0;
}

// [코드 평가]
// 정확한 풀이. j = col+1로 수정 후 오른쪽 대각선 검사 올바름
// 열/좌대각/우대각 세 방향 모두 검사, 선택-재귀-취소 패턴 올바르게 적용됨
