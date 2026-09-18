#include <stdio.h>

#define SIZE 8

int board[SIZE][SIZE] = {0};
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int is_valid(int x, int y)
{
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == 0;
}

int count_next_moves(int x, int y)
{
    int i, count = 0;
    int nx, ny;

    for (i = 0; i < 8; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (is_valid(nx, ny))
        {
            count++;
        }
    }

    return count;
}

int solve(int x, int y, int step)
{
    int i, j;
    int next[8][3];
    int count = 0;
    int nx, ny;
    int candidate_count;

    board[x][y] = step;

    if (step == SIZE * SIZE)
    {
        return 1;
    }

    for (i = 0; i < 8; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (!is_valid(nx, ny))
        {
            continue;
        }

        candidate_count = count_next_moves(nx, ny);
        next[count][0] = nx;
        next[count][1] = ny;
        next[count][2] = candidate_count;
        count++;
    }

    for (i = 0; i < count; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (next[j][2] < next[i][2])
            {
                int tmp0 = next[i][0], tmp1 = next[i][1], tmp2 = next[i][2];
                next[i][0] = next[j][0];
                next[i][1] = next[j][1];
                next[i][2] = next[j][2];
                next[j][0] = tmp0;
                next[j][1] = tmp1;
                next[j][2] = tmp2;
            }
        }
    }

    for (i = 0; i < count; i++)
    {
        nx = next[i][0];
        ny = next[i][1];

        if (solve(nx, ny, step + 1))
        {
            return 1;
        }
    }

    board[x][y] = 0;
    return 0;
}

int main(void)
{
    int startx, starty;
    int i, j;

    printf("输入起始点（行 列）： ");
    scanf("%d %d", &startx, &starty);

    if (startx < 0 || startx >= SIZE || starty < 0 || starty >= SIZE)
    {
        printf("起始点必须在 0 到 7 的范围内！\n");
        return 1;
    }

    if (solve(startx, starty, 1))
    {
        printf("游历完成!\n");
    }
    else
    {
        printf("游历失败！\n");
        return 0;
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%3d", board[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
