#include <stdio.h>

int main()
{

    float f = 0.1;
    double d = 0.1;
    printf("float: %f\n", f);
    printf("double: %f\n", d);

    int i = (int)(f);
    printf("float cast to int: %d\n", i);
    printf("double cast to int: %d\n", (int)(d));

    int mensaje_secreto[] = {116, 104, 101, 32, 103, 105, 102, 116, 32, 111,
                             102, 32, 119, 111, 114, 100, 115, 32, 105, 115, 32, 116, 104, 101, 32,
                             103, 105, 102, 116, 32, 111, 102, 32, 100, 101, 99, 101, 112, 116, 105,
                             111, 110, 32, 97, 110, 100, 32, 105, 108, 108, 117, 115, 105, 111, 110};
    size_t length = sizeof(mensaje_secreto) / sizeof(int);

    char decoded[length];

    for (size_t i = 0; i < length; i++)
    {
        decoded[i] = (char)(mensaje_secreto[i]); // casting de int a char, (tipo de dato) (expression)
    }
    for (size_t i = 0; i < length; i++)
    {
        printf("%c", decoded[i]);
    }
    return 0;
}