#include <stdio.h>
#include <math.h>

int main(void)
{
clrscr();
int i, j, sum = 0, c = 0, n, st, temp;
int a[20], b[20], dd[20];
do {
    printf("Enter the block number between 0 and 200: ");
    scanf("%d", &st);
} while (st >= 200 || st < 0);

printf("Our disk head is on the %d block\n", st);
a[0] = st;

printf("Enter the number of requests: ");
scanf("%d", &n);

printf("Enter requests: ");
for (i = 1; i <= n; i++) {
    printf("Enter request %d: ", i);
    scanf("%d", &a[i]);
    while (a[i] >= 200 || a[i] < 0) {
        printf("Block number must be between 0 and 200!\n");
        printf("Enter request %d: ", i);
        scanf("%d", &a[i]);
    }
}

for (i = 0; i <= n; i++)
    dd[i] = a[i];

int s = a[0];
for (i = 0; i <= n; i++)
    for (j = i + 1; j <= n; j++)
        if (dd[i] > dd[j]) {
            temp = dd[i];
            dd[i] = dd[j];
            dd[j] = temp;
        }

for (i = 0; i <= n; i++) {
    if (s == dd[i]) {
        b[c] = st;
        for (j = i + 1; j <= n; j++)
            b[++c] = dd[j];
        for (j = i - 1; j >= 0; j--)
            b[++c] = dd[j];
    }
}

printf("\nLOOK TECHNIQUE:\n");
printf("DISK QUEUE:\t");
for (i = 0; i <= n; i++)
    printf("%d\t", a[i]);
printf("\nACCESS ORDER:\t");
for (i = 0; i <= c; i++) {
    printf("%d\t", b[i]);
    if (i != c)
        sum += abs(b[i] - b[i + 1]);
}
printf("\n\nTotal head movements: %d\n", sum);
getch();
return 0;
}
