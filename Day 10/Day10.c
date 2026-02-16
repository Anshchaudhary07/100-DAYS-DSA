#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int left, right;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    left = 0;
    right = strlen(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("The string is a Palindrome\n");
    else
        printf("The string is NOT a Palindrome\n");

    return 0;
}