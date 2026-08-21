#include <stdio.h>

int main()
{
    char data[90], stuffed[90], destuffed[90];
    int i, j = 0, count = 0;

    // Sender Side
    printf("Enter String: ");
    scanf("%s", data);

    printf("\nSender Side\n");
    printf("Before Stuffing input: %s\n", data);

    // Bit Stuffing
    for(i = 0; data[i] != '\0'; i++)
    {
        stuffed[j++] = data[i];

        if(data[i] == '1')
            count++;
        else
            count = 0;

        if(count == 5)
        {
            stuffed[j++] = '0';
            count = 0;
        }
    }
    stuffed[j] = '\0';
    printf("After Stuffing output: %s\n", stuffed);
    printf("\nReceiver Side\n");
    printf("Before De-stuffing input: %s\n", stuffed);
    j = 0;
    count = 0;
    for(i = 0; stuffed[i] != '\0'; i++)
    {
        destuffed[j++] = stuffed[i];

        if(stuffed[i] == '1')
            count++;
        else
            count = 0;

        if(count == 5)
        {
            i++;     
            count = 0;
        }
    }
    destuffed[j] = '\0';
    printf("After De-stuffing output: %s\n", destuffed);
    return 0;
}