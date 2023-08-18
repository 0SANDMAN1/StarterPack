#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int length = strlen(s);

    for (int i = 0; i < length / 2; ++i)
    {
        char temp = s[i];

        s[i] = s[length - i - 1];

        s[length - i - 1] = temp;
    }
}

int main()
{
    char text[1000];

    printf("Enter Text Here: ");

    scanf(" %[^\n]", text); //to ignore leading white spaces and allow spaces in the input string.

    reverse(text);

    printf("Reversed Text: %s\n", text);

    return 0;
}
