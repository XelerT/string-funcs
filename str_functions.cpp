#include <stdio.h>
#include <string.h>
#include <assert.h>

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t count);
size_t my_strlen(const char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *lhs, const char *rhs);
int my_strncmp(const char *lhs, const char *rhs, size_t count);

int main()
{
        char arr1[] = "afaQWERTY";
        char arr2[] = "dadsQWERTY";
        char arr3[] = "1234";

        char *str1 = arr1;
        char *str2 = arr2;
        char *str3 = arr3;

        printf("%d \n", strncmp(str1, str2, 3));
        printf("%d \n", my_strncmp(str1, str2, 3));

        return 0;
}

char *my_strcpy(char *dest, char const *src)
{
        assert(dest);
        assert(src);

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
        assert(dest);
        assert(src);

        char *p = dest;
        size_t len = my_strlen(src);

                for (; count > 0 && count < len--; count--)
                        *dest++ = *src++;
                if (count < len)
                        for (; 0 < count; count--)
                                *dest++ = '\0';

        return p;
}

size_t my_strlen(const char *str)
{
        assert(str);

        size_t i = 0;
        for(; *str++ != '\0'; i++);

        return i;
}

char *my_strcat(char *dest, const char *src)
{
        assert(dest);
        assert(src);

        char *p = dest;
        int free_length = my_strlen(dest);
        for (; *dest != '\0'; free_length++)
                dest++;

        free_length = sizeof(dest) / sizeof(dest[0]);
        printf("%d\n", free_length);
        if (my_strlen(src) > free_length) // TODO
                return NULL;

        dest = dest + my_strlen(dest);
        printf("%s %d\n", src, my_strlen(src));
        int src_len = my_strlen(src);
        for(int i = 0; i < src_len + 1; i++)
        {
                *dest++ = *src++;
        }

        return p;
}

int my_strcmp(const char *lhs, const char *rhs)
{
        const char *p = lhs;
        for (int i = 0; i < my_strlen(p); i++)
        {
                if (*lhs == *rhs)
                {
                        lhs++;
                        rhs++;
                } else if ((*lhs - *rhs) > 0)

                        return 1;
                else
                        return -1;
        }

        return 0;
}

int my_strncmp(const char *lhs, const char *rhs, size_t count)
{
        const char *p = lhs;
        for (size_t i = 0; i < count; i++)
        {
                if (*lhs == *rhs)
                {
                        lhs++;
                        rhs++;
                } else if ((*lhs - *rhs) > 0)

                        return  1;
                else
                        return -1;
        }

        return 0;
}
