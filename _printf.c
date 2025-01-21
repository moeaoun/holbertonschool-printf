#include "main.h"

/* Function prototypes */
int print_number(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex_lower(unsigned int n);
int print_hex_upper(unsigned int n);
int print_binary(unsigned int n);

/**
 * _printf - Function that produces output according to a format.
 * @format: The format string containing the directives.
 *
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%' && (*(ptr + 1) == 'c' || *(ptr + 1) == 's' ||
                            *(ptr + 1) == '%' || *(ptr + 1) == 'd' ||
                            *(ptr + 1) == 'i' || *(ptr + 1) == 'b' ||
                            *(ptr + 1) == 'u' || *(ptr + 1) == 'o' ||
                            *(ptr + 1) == 'x' || *(ptr + 1) == 'X'))
        {
            if (*(ptr + 1) == 'c')  /* Handle character */
            {
                char c = va_arg(args, int);

                write(1, &c, 1);
                count++;
            }
            else if (*(ptr + 1) == 's')  /* Handle string */
            {
                char *str = va_arg(args, char *);

                if (str == NULL)
                {
                    str = "(null)";
                }

                while (*str)
                {
                    write(1, str++, 1);
                    count++;
                }
            }
            else if (*(ptr + 1) == '%')  /* Handle percentage */
            {
                write(1, "%", 1);
                count++;
            }
            else if (*(ptr + 1) == 'd' || *(ptr + 1) == 'i')  /* Handle integer */
            {
                int num = va_arg(args, int);

                count += print_number(num);
            }
            else if (*(ptr + 1) == 'b')  /* Handle binary */
            {
                unsigned int num = va_arg(args, unsigned int);

                count += print_binary(num);
            }
            else if (*(ptr + 1) == 'u')  /* Handle unsigned integer */
            {
                unsigned int num = va_arg(args, unsigned int);

                count += print_unsigned(num);
            }
            else if (*(ptr + 1) == 'o')  /* Handle octal */
            {
                unsigned int num = va_arg(args, unsigned int);

                count += print_octal(num);
            }
            else if (*(ptr + 1) == 'x')  /* Handle lowercase hexadecimal */
            {
                unsigned int num = va_arg(args, unsigned int);

                count += print_hex_lower(num);
            }
            else if (*(ptr + 1) == 'X')  /* Handle uppercase hexadecimal */
            {
                unsigned int num = va_arg(args, unsigned int);

                count += print_hex_upper(num);
            }

            ptr++;  /* Skip the next character */
        }
        else
        {
            write(1, ptr, 1);
            count++;
        }
    }

    va_end(args);
    return (count);
}

/**
 * print_binary - Helper function to print an unsigned integer as binary.
 * @n: The unsigned integer to print in binary.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int n)
{
    int count = 0;

    if (n / 2 != 0)
    {
        count += print_binary(n / 2);
    }

    write(1, &"01"[n % 2], 1);
    count++;

    return (count);
}

/**
 * print_number - Helper function to print an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
    int count = 0;
    unsigned int num;

    /* Handle negative numbers */
    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }

    /* Print the digits of the number */
    if (num / 10 != 0)
    {
        count += print_number(num / 10);
    }

    write(1, &"0123456789"[num % 10], 1);
    count++;

    return (count);
}

/**
 * print_unsigned - Helper function to print an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int n)
{
    int count = 0;

    /* Handle the special case of zero */
    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    if (n / 10 != 0)
    {
        count += print_unsigned(n / 10);
    }

    write(1, &"0123456789"[n % 10], 1);
    count++;

    return (count);
}

/**
 * print_octal - Helper function to print an unsigned integer in octal.
 * @n: The unsigned integer to print in octal.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int n)
{
    int count = 0;

    /* Handle the special case of zero */
    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    if (n / 8 != 0)
    {
        count += print_octal(n / 8);
    }

    write(1, &"01234567"[n % 8], 1);
    count++;

    return (count);
}

/**
 * print_hex_lower - Helper function to print an unsigned integer in lowercase hexadecimal.
 * @n: The unsigned integer to print in lowercase hexadecimal.
 *
 * Return: The number of characters printed.
 */
int print_hex_lower(unsigned int n)
{
    int count = 0;

    /* Handle the special case of zero */
    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    if (n / 16 != 0)
    {
        count += print_hex_lower(n / 16);
    }

    write(1, &"0123456789abcdef"[n % 16], 1);
    count++;

    return (count);
}

/**
 * print_hex_upper - Helper function to print an unsigned integer in uppercase hexadecimal.
 * @n: The unsigned integer to print in uppercase hexadecimal.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(unsigned int n)
{
    int count = 0;

    /* Handle the special case of zero */
    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    if (n / 16 != 0)
    {
        count += print_hex_upper(n / 16);
    }

    write(1, &"0123456789ABCDEF"[n % 16], 1);
    count++;

    return (count);
}

