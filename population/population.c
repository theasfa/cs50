#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold

    int num_years = 0;
    int n = start_size;
    while (n < end_size)
    {
        n = n + (n / 3) - (n / 4);
        num_years++;
    }

//    for (int num_years = 0, n < end_size, num_years++)
//    {
//       int n = n + (n/3) - (n/4);
//    }

    // TODO: Print number of years
    
    printf("Years: %i", num_years);
}