#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    long number = get_long("Number: ");

    //Get number of digits in the number provided
    long num_digits = floor(log10(labs(number))) + 1;

    // Multiply each alternating digit in the number by 2, and store into double_alt_num
    long double_alt_num;
    int sum_double_alt_num = 0;
    long num_digits_double = 0;

    for (int n = 2; n <= num_digits + 2;
         n += 2) // Multiply alternating digits starting from position 1 with 2, and determine number of digits of the product
    {
        for (int m = 1; m <= num_digits_double; m++, n += 2) // Sum up digits of the product of alt_num
        {
            n = n - 2;

            long double_num = ((double_alt_num % (long) pow(10, m)) - (double_alt_num % (long) pow(10, m - 1))) / pow(10,
                              m - 1); //Go through each digit in the product

            sum_double_alt_num += double_num; //Add sum of digits to total sum

        }
        long alt_num = ((number % (long) pow(10, n)) - (number % (long) pow(10, n - 1))) / pow(10, n - 1); //Alternating digits

        double_alt_num = alt_num * 2; //Multiply digit by 2

        num_digits_double = floor(log10(labs(double_alt_num))) + 1; //Determine number of digits in product
    }


    // Sum up the other alternating numbers and store into alt_num
    int sum_alt_num = 0;

    for (int n = 1; n <= num_digits; n += 2) // Sum up alternating digits starting from position 0
    {
        long alt_num = ((number % (long) pow(10, n)) - (number % (long) pow(10, n - 1))) / pow(10, n - 1);

        sum_alt_num += alt_num;
    }

    // Sum up total of the two main loops
    int total_sum = sum_double_alt_num + sum_alt_num;

    // Determine last and second to last digit
    int last_digit = ((number % (long) pow(10, num_digits)) - (number % (long) pow(10, num_digits - 1))) / pow(10, num_digits - 1);
    int second_last_digit = ((number % (long) pow(10, num_digits - 1)) - (number % (long) pow(10, num_digits - 2))) / pow(10, 
                            num_digits - 2);


    if (total_sum % 10 == 0 && num_digits == 15 && last_digit == 3 && (second_last_digit == 4 || second_last_digit == 7))
    {
        printf("AMEX\n");
    }
    else if (total_sum % 10 == 0 && num_digits == 16 && last_digit == 5 && second_last_digit >= 1 && second_last_digit <= 5)
    {
        printf("MASTERCARD\n");
    }
    else if (total_sum % 10 == 0 && (num_digits == 13 || num_digits == 16) && last_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}