#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing _printf function
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "I am a string !");  /* Example with string */
    printf("String:[%s]\n", "I am a string !");

    _printf("Percent:[%%]\n");  /* Handle percentage character */
    printf("Percent:[%%]\n");

    return (0);
}

