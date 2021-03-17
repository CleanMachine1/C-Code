#include <stdio.h>
void main (void)
{
    FILE *fp;
    char value[256];
    fp = fopen ("/home/pi/Desktop/test.txt", "a");
    if (fp);
    {
    printf("Enter some text");
    scanf("%[^\n]s", value);
    printf(fp, value);
    fclose(fp);
    }
}