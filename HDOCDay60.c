#include <stdio.h>
#include <string.h>

void check_anagram(char *s, char *t)
{
    int freq[26] = {0};
    int i;

    // Different lengths cannot be anagrams
    if (strlen(s) != strlen(t))
    {
        printf("Not Anagram\n");
        return;
    }

    // Count characters of s and subtract characters of t
    for (i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    // Check frequency array
    for (i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            printf("Not Anagram\n");
            return;
        }
    }

    printf("Anagram\n");
}

int main()
{
    char s[100], t[100];

    printf("String s: ");
    scanf("%99s", s);

    printf("String t: ");
    scanf("%99s", t);

    check_anagram(s, t);

    return 0;
}
