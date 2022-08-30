#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t count);
size_t my_strlen(const char *str);
char *my_strcat(char *dest, const char *src);

int main()
{
        char arr1[] = "qwerty";
        char arr2[] = "QWERTY";
        char arr3[] = "1234";

        char *str1 = arr1;
        char *str2 = arr2;
        char *str3 = arr3;

        str1 = my_strcpy(str1, str3);
        printf("%s\n", str1);

        return 0;
}

char *my_strcpy(char *dest, char const *src)
{
        char *p = dest;
        if (my_strlen(src) > my_strlen(dest))
        {
                while (*src)
                        *dest++ = *src++;
                *dest = '\0';
        }
        else
        {
                while (*src)
                        *dest++ = *src++;
        }

        return p;
}

char *my_strncpy(char *dest, char const *src, size_t count)
{
        char *p = dest;
        int len = my_strlen(src);

                for (; count > 0 && count < len--; count--)
                        *dest++ = *src++;
                if (count < len)
                        for (; 0 < count; count--)
                                *dest++ = '\0';

        return p;
}

size_t my_strlen(const char *str)
{
        size_t i = 0;
        for(; *str++ != '\0'; i++);

        return i;
}

char *my_strcat(char *dest, const char *src)
{
        char *p = dest;
        dest = dest + my_strlen(dest);
        if ()
        return 0;
}
