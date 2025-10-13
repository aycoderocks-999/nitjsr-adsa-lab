#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

void rabin_karp(char *txt, char *pat)
{
    int n = strlen(txt);
    int m = strlen(pat);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
                if (txt[i + j] != pat[j])
                    break;

            if (j == m)
                printf("Pattern found at index %d\n", i);
        }

        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0)
                t = t + q;
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

    rabin_karp(txt, pat);

    return 0;
}
