#include "main.h"

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
            *(ptr + 1) == '%'))
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
                    str = "(null)";

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

