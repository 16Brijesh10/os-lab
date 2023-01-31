#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;

int main()
{
    int i, j, sum = 0, c = 0, n, start, temp, t, current;
    int requests[20], order[20], sorted[20];

	clrscr();

    do
    {
        printf("Enter the block number between 0 and 200: ");
        scanf("%d", &start);
    } while ((start >= 200) || (start < 0));

    printf("Our disk head is on the %d block", start);
    requests[0] = start;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for (i = 1; i <= n; i++)
    {
        printf("Enter %d request: ", i);
        scanf("%d", &requests[i]);
        do
        {
            if ((requests[i] > 200) || (requests[i] < 0))
            {
                printf("Block number must be between 0 and 200!");
            }
        } while ((requests[i] > 200) || (requests[i] < 0));
    }

    for (i = 0; i <= n; i++)
        sorted[i] = requests[i];

    current = requests[0];
    for (i = 0; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            if (sorted[i] > sorted[j])
            {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }

    for (i = 0; i <= n; i++)
    {
        if (current == sorted[i])
        {
            order[c] = start;
            for (j = i + 1; j <= n; j++)
                order[++c] = sorted[j];
            for (j = i - 1; j >= 0; j--)
                order[++c] = sorted[j];
        }
    }

    printf("\n\t\tLOOK TECHNIQUE: ");
    printf("\nDISK QUEUE:");
    for (i = 0; i <= n; i++)
        printf("\t%d", requests[i]);

    printf("\n\nACCESS ORDER:");
    for (i = 0; i <= c; i++)
    {
        printf("\t%d", order[i]);
        if (i != c)
            sum += abs(order[i] - order[i + 1]);
    }

    printf("\n\nTotal number of head movements: %d", sum);
    return 0;
    getch();
}
