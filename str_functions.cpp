#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

char *my_strcpy (char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t count);

size_t my_strlen(const char *str);

char *my_strcat(char *dest, const char *src);

int my_strcmp (const char *lhs, const char *rhs);
int my_strncmp(const char *lhs, const char *rhs, size_t count);

char *my_strchr (const char *str, int ch);
char *my_strrchr(const char *str, int ch);

size_t my_strspn (const char *dest, const char *src);
size_t my_strcspn(const char *dest, const char *src);

char *my_strpbrk(const char* dest, const char* breakset);

char *my_strstr(const char* str, const char* substr);

int main()
{
        char arr1[30] = "6ab7dc312$#@";
        char arr2[] =   "6ab7dc312$#@";
        char arr3[] =   "6";

        char *str1 = arr1;
        char *str2 = arr2;
        char *str3 = arr3;

        printf("%s\n", my_strstr(str1, str3));
        printf("%s\n",    strstr(str1, str3));

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
        while (*str++)
                i++;

        return i;
}

char *my_strcat(char *dest, const char *src)
{
        assert(dest);
        assert(src);

        char *wr = dest;
        while (*wr)
                wr++;

        while (*src)
              *wr++ = *src++;

        return dest;
}

int my_strcmp(const char *lhs, const char *rhs)
{
        assert(lhs);
        assert(rhs);

        while (*(lhs - 1))
                if (*lhs++ != *rhs++)
                        return  (*--lhs - *--rhs) / fabs(*lhs - *rhs);

        return 0;
}

int my_strncmp(const char *lhs, const char *rhs, size_t count)
{
        assert(lhs);
        assert(rhs);

        while (*(lhs - 1) && count--)
                if (*lhs++ != *rhs++)
                        return  (*--lhs - *--rhs) / fabs(*lhs - *rhs);

        return 0;
}

char *my_strchr(const char *str, int ch)
{
        assert(str);

        while (*str != ch)
                if (*str++ == '\0')
                        return nullptr;

        return (char*) str;
}

size_t my_strspn(const char *dest, const char *src)
{
        assert(dest);
        assert(src);

        size_t i = 0;
        while (*(dest + i))
                for (int j = 0; *(src + j); j++)
                        if (*(dest + i) == *(src + j))
                        {
                                i++;
                                break;
                        } else if (!*(src + j + 1))
                        {
                                return i;
                        }
        return i;
}

size_t my_strcspn (const char *dest, const char *src)
{
        assert(dest);
        assert(src);

        size_t i = 0;
        while (*(dest + i))
        {
                for (int j = 0; *(src + j); j++)
                        if (*(dest + i) == *(src + j))
                                return i;
                i++;
        }

        return i;
}

char* my_strpbrk(const char* dest, const char* breakset) //WTF
{
        size_t i = 0;
        while (*(dest + i))
        {
                for (int j = 0; *(breakset + j); j++)
                        if (*(dest + i) == *(breakset + j))
                                return (char*) (dest + i);
                i++;
        }

        return (char*) (dest + i);
}

char *my_strstr(const char* str, const char* substr)
{
        int a = 1;
        for (int i = 0; *substr; i++)
        {
                a = 1;
                for (int j = 0; *substr && a; j++)
                {
                        if (*str != substr[j])
                                a = 0;
                        str++;
                        if (substr[j] == '\0')
                        {
                                str -= (j + 1);
                                return (char*) str;
                        }
                }
        }

        return (char*) str;
}
