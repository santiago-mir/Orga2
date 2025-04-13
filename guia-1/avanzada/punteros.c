#include <stdio.h>
#include <stdint.h>
#include <string.h>
void to_upper_case(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - ('a' - 'A');
        }
        str++;
    }
}

size_t length(const char *s)
{
    size_t res = strlen(s);
    return res;
}

int main()
{
    char literal[] = "Hola que Tal";
    char hola[] = "Hola";
    printf("Valor del string %s\n", literal);
    to_upper_case(literal);
    printf("Valor en mayusc: %s\n", literal);
    char nuevo[length(hola) + 1];
    printf("Valor del string %s\n", nuevo);
    strcpy(nuevo, hola);
    printf("Valor del string %s\n", nuevo);
    int are_equal = strcmp(nuevo, hola);
    printf("Nuevo y hola son iguales?: %d", are_equal);

    return 0;
}