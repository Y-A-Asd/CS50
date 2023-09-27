#include <stdio.h>

#include <cs50.h>

int main(void)
{
    // Get a name and say hello
    string name = get_string("what is your name \n");

    printf("hello, %s\n", name);

}