#include <stdio.h>
#include <stdlib.h>

void spigot(int n) {
    int len = (10 * n / 3) + 1;
    int *digits = (int *)malloc(sizeof(int) * len);
    if (digits == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < len; i++) {
        digits[i] = 2;
    }

    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = len - 1; j > 0; j--) {
            digits[j] = digits[j] * 10 + carry;
            int temp = digits[j] / (j * 2 + 1);
            digits[j] = digits[j] % (j * 2 + 1);
            carry = temp * j;
        }

        digits[0] = digits[0] * 10 + carry;
        int q = digits[0] / 10;
        digits[0] = digits[0] % 10;

        printf("%d", q);
    }

    free(digits);
}

int main() {
    int n;
    printf("Enter the number of digits to generate: ");
    scanf("%d", &n);
    printf("Pi: 3.");
    spigot(n);
    printf("\n");
    getch();
    return 0;
}
