#include <stdio.h>


void spigot(int n)
{

    int ft=0,len = (10 * n / 3) + 2;  // Corrected formula
    int *digits = (int *)malloc(sizeof(int) * len);
    if (digits == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < len; i++)
    {
        digits[i] = 2;
    }

    for (int i = 0; i < n; i++)
    {
        int carry = 0;
        for (int j = len - 1; j > 0; j--)
        {
            digits[j] = digits[j] * 10 + carry;
            int temp = digits[j] / (j * 2 + 1);
            digits[j] = digits[j] % (j * 2 + 1);
            carry = temp * j;
        }

        digits[0] = digits[0] * 10 + carry;
        int q = digits[0] / 10;
        digits[0] = digits[0] % 10;

        printf("%d", q);
        if(ft==0)
        {
            printf(".");
            ft++;
        }
    }

    free(digits);
}

int main()
{
    int n;
    printf("Enter the number of digits to generate: ");
    scanf("%d", &n);
    printf("Pi: ");
    spigot(n);
    printf("\n");
    return 0;
}
