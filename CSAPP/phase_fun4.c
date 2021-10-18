#include <stdio.h>

int func4(int, int, int);

int main() {
    int res = func4(3, 0, 14);
    printf("%d\n", res);
}

int func4(int a, int b, int c) {
    // printf("%d, %d, %d\n", a, b ,c);
    int res = c;
    res -= b;
    int d = c;
    d >>= 31;
    res += d;
    res >>= 1;
    d = res + b * 1;

    if (d <= a) {
        res = 0;
        if (d >= a) {
            return res;
        } else {
            b = d + 1;
            res = func4(a, b, c);
            res = res * 2 + 1;
            return res;
        }
    } else {
        c = d - 1;
        res = func4(a, b, c);
        res = res*2;
        return res;
    }
}
