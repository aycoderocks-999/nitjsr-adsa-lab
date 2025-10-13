#include <stdio.h>
#include <string.h>

void computeLPSArray(char *pat, int m, int *lps)
{
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *txt, char *pat)
{
    int n = strlen(txt);
    int m = strlen(pat);
    int lps[m];
    computeLPSArray(pat, m, lps);

    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
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

    KMP(txt, pat);

    return 0;
}
