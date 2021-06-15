#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int in = atoi(argv[1]);
    string text = get_string("plaintext: ");
    int key = in % 26;
    //  int key = 2;
    // printf("dirkey: %s\n", argv[1]);

    //printf("key:  %i\n", key);
    int cip = 0;
    //looping throu the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //rotationg capital
        if (text[i] <= 'Z' && text[i] >= 'A')
        {

            cip = (text[i] + key);
            while (cip > 90)
            {
                cip = cip - 26;
            }
            //printf("%i\n", cip);
            text[i] = (char)cip;
        }
        //rotating small
        else if (text[i] <= 'z' && text[i] >= 'a')
        {
            cip = 0;
            cip = (text[i] + key);
            while (cip > 122)
            {
                cip = cip - 26;
            }
            //printf("%i\n", cip);
            text[i] = (char)cip;  
        }
        //skipping all others
        else
        {
            text[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", text);
}