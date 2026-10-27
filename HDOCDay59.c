#include <stdio.h>
#include <string.h>

void longest_unique_substring(char *s)
{
    int maxLength = 0;
    int start = 0;
    int last[256];

    // Initialize all character positions to -1
    for (int i = 0; i < 256; i++)
        last[i] = -1;

    // Empty string
    if (*s == '\0')
    {
        printf("0\n");
        return;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        unsigned char ch = s[i];

        // If character is already present in current substring
        if (last[ch] >= start)
            start = last[ch] + 1;

        last[ch] = i;

        int currentLength = i - start + 1;

        if (currentLength > maxLength)
            maxLength = currentLength;
    }

    printf("Length of longest substring: %d\n", maxLength);
}

int main()
{
    char s[1000];

    // Read the string
    fgets(s, sizeof(s), stdin);

    // Remove newline added by fgets
    s[strcspn(s, "\n")] = '\0';

    // Pass string using its address
    longest_unique_substring(s);

    return 0;
}
