#include <stdio.h>
#include <string.h>
#include <ctype.h>
//A Palindrome tester with the added bonus of only using the first worf
//And also having an auto lowercase feature to make it work better if the user enters a capital
void test(char test1[256])
{
    int l = 0; 
    int h = strlen(test1) - 1; 
  
    while (h > l) 
    { 
        if (test1[l++] != test1[h--]) 
        { 
            printf("%s is Not a Palindrome", test1); 
            return; 
        } 
    } 
    printf("%s is a palindrome", test1); 
} 


void main(void)
{
    char ori[256];
    char rev[256];
    char *p;
    printf("What is the word you want to reverse");
    scanf("%s", ori);
    
    for (p = ori; *p != '\0'; ++p)
    {
       *p = tolower(*p);      
    }
    test(ori);
}