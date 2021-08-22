// paper_cutter.c
// Takes in the dimensions of a paper,
// and produces the next paper according to
// the algorithm that if
// A(n - 1) = l * b, then
// A(n) = min{l, b} * int(max{l, b} / 2)

// Author: Adarsh, Date: 06/09/2020

# include <stdio.h>

int main()
{
    int l0, l1, b0, b1;

    printf("Enter dimensions of paper:\n");
    scanf("%d, %d", &l0, &b0);

    if (l0 < b0)
    {
        l1 = l0;
        b1 = b0 / 2;
    }
    else
    {
        l1 = b0;
        b1 = l0 / 2;
    }

    printf("\nPaper 2 dimensions: %d x %d", l1, b1);
    return 0;
}
