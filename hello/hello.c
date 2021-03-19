#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //asks the name of the user and prints it out
    string name = get_string("What is your name?\n");
    
    printf("hello, %s\n", name);
}