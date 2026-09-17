#include <stdio.h>
#include <stdlib.h>

#define BLUE 'b'
#define RED 'r'
#define WHITE 'w'

#define SWAP(x, y) do { \
    char temp = color[x]; \
    color[x] = color[y]; \
    color[y] = temp; \
} while (0)

int main(void)
{
    char color[] = {'r', 'w', 'b', 'w', 'w', 'b', 'r', 'b', 'w', 'r'};
    const int n = sizeof(color) / sizeof(color[0]);
    int left = 0;
    int cur = 0;
    int right = n - 1;
    int i;

    printf("Before: ");
    for (i = 0; i < n; i++)
    {
        printf("%c ", color[i]);
    }
    printf("\n");

    while (cur <= right)
    {
        if (color[cur] == RED)
        {
            SWAP(left, cur);
            left++;
            cur++;
        }
        else if (color[cur] == WHITE)
        {
            cur++;
        }
        else
        {
            SWAP(cur, right);
            right--;
        }
    }

    printf("After:  ");
    for (i = 0; i < n; i++)
    {
        printf("%c ", color[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}