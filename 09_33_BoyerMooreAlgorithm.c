#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

void badCharHeuristic(char *pat, int m, int badchar[])
{
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (int i = 0; i < m; i++)
        badchar[(unsigned char)pat[i]] = i;
}

void boyer_moore(char *txt, char *pat)
{
    int n = strlen(txt);
    int m = strlen(pat);

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= n - m)
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            printf("Pattern found at index %d\n", s);
            s += (s + m < n) ? m - badchar[(unsigned char)txt[s + m]] : 1;
        }
        else
        {
            int shift = j - badchar[(unsigned char)txt[s + j]];
            s += (shift > 1) ? shift : 1;
        }
    }
}

int main()
{
    char txt[1000], pat[1000];
    printf("Enter text: ");
    fgets(txt, sizeof(txt), stdin);
    printf("Enter pattern: ");
    fgets(pat, sizeof(pat), stdin);

    txt[strcspn(txt, "\n")] = 0;
    pat[strcspn(pat, "\n")] = 0;

    boyer_moore(txt, pat);

    return 0;
}
