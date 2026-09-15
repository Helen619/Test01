#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_N 100

int main(void) {
    int n;
    int fib[MAX_N] = {0};
    int i;

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    printf("请输入要输出的斐波那契项数 n: ");
    if (scanf("%d", &n) != 1) {
        printf("输入有误！\n");
        return 1;
    }

    if (n <= 0) {
        printf("n 必须大于 0。\n");
        return 1;
    }

    if (n > MAX_N) {
        printf("n 不能超过 %d。\n", MAX_N);
        return 1;
    }

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }

    printf("\n");
    return 0;
}