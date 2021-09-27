#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *c1, char *c2)
{
    char c3 = *c1;
    *c1 = *c2;
    *c2 = c3;
}

char *sum(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    char *c = (char *)calloc(5000, sizeof(char));
    int k = 0;
    int carry = 0;
    int i = la - 1, j = lb - 1;

    while (i >= 0 && j >= 0)
    {
        int t = (a[i] - '0') + (b[j] - '0') + carry;
        c[k] = (t % 10) + '0';
        carry = t / 10;
        k++;
        i--;
        j--;
    }
    // ------------------------
    if (i >= 0 && j < 0)
    {
        while (i >= 0)
        {
            if (carry > 0)
            {
                int t = (a[i] - '0') + carry;
                c[k] = (t % 10) + '0';
                carry = t / 10;
                k++;
                i--;
            }
            if (carry == 0)
            {
                while (i >= 0)
                {
                    c[k] = a[i];
                    k++;
                    i--;
                }
            }
        }
    }
    //-------------------
    if (j >= 0 && i < 0)
    {
        while (j >= 0)
        {
            if (carry > 0)
            {
                int t = (b[j] - '0') + carry;
                c[k] = (t % 10) + '0';
                carry = t / 10;
                k++;
                j--;
            }
            else
            {
                while (j >= 0)
                {
                    c[k] = b[j];
                    k++;
                    j--;
                }
            }
        }
    }
    if (carry != 0 && j < 0 && i < 0)
    {
        c[k] = carry + '0';
    }
    // -----------
    for (int w = 0; w < strlen(c) / 2; w++)
    {
        swap(c + w, c + strlen(c) - w - 1);
    }
    return c;
}
int main()
{
    int n;
    printf("\nEnter number :\n");
    scanf("%d", &n);
    char a[5000] = "0", b[5000] = "1";
    char *c = (char *)calloc(5000, sizeof(char));
    if (n == 0)
    {
        c = "0";
    }
    else if (n == 1||n==2)
    {
        c = "1";
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            c = sum(a, b);
            strcpy(a, b);
            strcpy(b, c);
        }
    }
    printf("Fibonacci value :\n");
    printf("%s\n\n", c);

    return 0;
}
