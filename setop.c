
#include <stdio.h>

struct bit
{
    unsigned char x : 1;
};

int Uset[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, SIZE = 10;

void main()
{
    void readset(struct bit [], int);
    void printset(struct bit []);
    void unionset(struct bit [], struct bit [], struct bit []);
    void intersect(struct bit [], struct bit [], struct bit []);
    void difference(struct bit [], struct bit [], struct bit []);

    struct bit a[10] = {0}, b[10] = {0}, c[10] = {0};

    int n;

    printf("No. of elements in set A: ");
    scanf("%d", &n);
    readset(a, n);

    printf("No. of elements in set B: ");
    scanf("%d", &n);
    readset(b, n);

    printf("Set A: ");
    printset(a);

    printf("Set B: ");
    printset(b);

    unionset(a, b, c);
    printf("A union B = ");
    printset(c);

    intersect(a, b, c);
    printf("A intersection B = ");
    printset(c);

    difference(a, b, c);
    printf("A - B = ");
    printset(c);
}

/* To read a set and store it as bit string */

void readset(struct bit a[], int n)
{
    int i, x, k;

    printf("Enter %d elements: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);

        for (k = 0; k < SIZE; k++)
        {
            if (Uset[k] == x)
            {
                a[k].x = 1;
                break;
            }
        }
    }

    return;
}

/* To print a set from bit string representation */

void printset(struct bit a[])
{
    int k;

    printf("{");

    for (k = 0; k < SIZE; k++)
    {
        if (a[k].x == 1)
            printf("%d ", Uset[k]);
    }

    printf("}\n");

    return;
}

/* To find union of two sets using bit string */

void unionset(struct bit a[], struct bit b[], struct bit c[])
{
    int k;

    for (k = 0; k < SIZE; k++)
        c[k].x = a[k].x | b[k].x;

    return;
}

/* To find intersection of two sets */

void intersect(struct bit a[], struct bit b[], struct bit c[])
{
    int k;

    for (k = 0; k < SIZE; k++)
        c[k].x = a[k].x & b[k].x;

    return;
}

/* To find difference of two sets */

void difference(struct bit a[], struct bit b[], struct bit c[])
{
    int k;

    for (k = 0; k < SIZE; k++)
        c[k].x = a[k].x & !b[k].x;

    return;
}

