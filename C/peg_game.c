/* peg_game.c

   This program finds the solution to the
   peg game like the Towers of Hanoi game.

   For n numbers, the optimal solution
   requires 2^(n)-1 steps.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int n = 3;
int N;
int count = 0;


int gen_num()
{
    int p = pow(10, n);
    int n = 0;

    for (int i = 1; i <= n + 1; i++)
    {
        n += i * p;
        p /= 10;
    }
    return n;
}

// Format to print a formation
void print_format(int a, int b, int c, int count)
{
	// 0 means the place is empty
    if (n % 2 == 0)
        printf("Step %3d: A:%09d  B:%09d  C:%09d\n", count, a, c, b);
    else
        printf("Step %3d: A:%09d  B:%09d  C:%09d\n", count, a, b, c);
}

// Returns the last non-zero digit of the peg
int last_digit(int peg)
{
    int d;
    for (int i = 0; i <= n; i++)
    {
        d = peg % 10;
        if (d != 0)
            return d;
        peg /= 10;
    }
    return 0;
}

// Returns the place multiplier of the last non-zero
// digit of the peg
int place_multiplier(int peg)
{
    for (int i = 0; i <= n; i++)
    {
        int d = peg % 10;
        if (d != 0)
            return i;
        peg /= 10;
    }
    return 0;
}

// moves last digit from a to b
void move_from(int* a, int* b)
{
    int l1 = last_digit(*a);

    int p1 = place_multiplier(*a);
    int p2 = place_multiplier(*b);
    //printf("%d\n", p2);

    p2 = *b == 0 ? n : p2 - 1;

    *a = *a - l1 * pow(10, p1);
    *b = *b + l1 * pow(10, p2);
    //printf("%d %d\n", *a, *b);
}

int check_and_move(int* a, int* b, int coin)
{
    int l1 = last_digit(*a);
    int l2 = last_digit(*b);

    if (l2 >= l1 || l1 == coin)// = for the case where both are empty
        return 0;

    move_from(a, b);
    return l1;
}

void play_peg(int a, int b, int c, int coin)
{
    print_format(a, b, c, count++);

    if (b == N && n % 2 == 0)
        return;
    if (c == N && n % 2 == 1)
        return;

    if (check_and_move(&a, &b, coin))
    {
        coin = last_digit(b);
        goto next;
    }
    else if (check_and_move(&a, &c, coin))
    {
        coin = last_digit(c);
        goto next;
    }
    else if (check_and_move(&b, &c, coin))
    {
        coin = last_digit(c);
        goto next;
    }
    else if (check_and_move(&b, &a, coin))
    {
        coin = last_digit(a);
        goto next;
    }
    else if (check_and_move(&c, &a, coin))
    {
        coin = last_digit(a);
        goto next;
    }
    else if (check_and_move(&c, &b, coin))
    {
        coin = last_digit(c);
        goto next;
    }

    next:
        play_peg(a, b, c, coin);

    return;
}

int main()
{
    N = gen_num(n - 1);
    play_peg(N, 0, 0, 0);
    return 0;
}
