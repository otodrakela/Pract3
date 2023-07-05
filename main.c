#include <stdio.h>
#include <stdlib.h>

int countNumbers(int r) {
    int aa[r+1][3];

    aa[1][0] = 2;  // Для однорозрядного числа
    aa[1][1] = 2;
    aa[1][2] = 0;

    for (int i = 2; i <= r; i++) {
        aa[i][0] = aa[i-1][0] + aa[i-1][1];  // Для чисел без однакових цифр поруч
        aa[i][1] = aa[i-1][0] + aa[i-1][1] + aa[i-1][2];  // Для чисел з однаковими цифрами на відстані 1
        aa[i][2] = aa[i-1][1] + aa[i-1][2];  // Для чисел з однаковими цифрами на відстані 2
    }

    return aa[r][0] + aa[r][1] + aa[r][2];
}

int main() {
    int r;

    scanf("%d", &r);

    int result = countNumbers(r);

    printf("%d\n", result);

    return 0;
}
