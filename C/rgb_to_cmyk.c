/* rgb_to_cmyk.c

   This program accepts an (R, G, B)
   tuple from the user and prints the
   equivalent (C, M, Y, K) tuple.

   Author: Adarsh
*/

# include <stdio.h>

float max(float red, float green, float blue)
{
    if (red >= green && red >= blue)
        return red;
    else if (green >= red && green >= blue)
        return green;
    else if (blue >= red && blue >= green)
        return blue;
}

int main()
{
    int R, G, B;
    float white, C, M, Y, K;

    printf("Enter an (R, G, B) tuple where all values");
    printf("\nare between 0 and 255:\n");
    scanf("(%d, %d, %d)", &R, &G, &B);

    float red = R / 255.0;
    float green = G / 255.0;
    float blue = B / 255.0;

    white = max(red, green, blue);

    if (white != 0)
    {
        C = (white - red) / white;
        M = (white - green) / white;
        Y = (white - blue) / white;
    }
    else
    {
        C = 0;
        M = 0;
        Y = 0;
    }
    K = 1 - white;

    printf("\nWhite        : %f", white);
    printf("\nCyan (C)     : %f", C);
    printf("\nMagenta (M)  : %f", M);
    printf("\nYellow (Y)   : %f", Y);
    printf("\nBlack (K)    : %f", K);
    printf("\n(C, M, Y, K) : (%f, %f, %f, %f)",
           C, M, Y, K);

    return 0;
}
