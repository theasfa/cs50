#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get positive integer between 0 and 9
    int n;
    do
    {
        n = get_int("Positive Integer (1-8): ");
    }
    while (n < 1 || n > 8);

    // Print out symmetrical stairs with n height and increasing width per line
    

    for (int i = 0; i <= n; i++) // Go to next line
    {
        for (int j = 0; j < i; j++) //left #
        {
            for (int k = j; k < 1; k++) //Middle space
            {
                for (int o = 0; o < (n - i); o++) //First space
                {
                    printf(" ");
                }
                for (int l = 0; l < i; l++) //right #
                {
                    printf("#");
                }
                printf("  ");
            }
            printf("#");
        }
        printf("\n");
    }

}


