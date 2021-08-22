/* matchstick.c

   This program plays a game
   of matchsticks with the user vs
   computer. In this game,
   1. There are 21 matchsticks
   2. The user and computer can pick up
      1, 2, 3, 4 matchsticks.
   3. The user moves first
   4. Whoever picks up last matchstick loses.

   The program is written so that
   computer always wins.

   Author: Adarsh
*/

# include <stdio.h>

int valid(int choice, int num)
{
    if (num > 4)
        return choice <= 4 && choice >= 1;
    return choice <= num && choice >= 1;
}

int main()
{
    int num;
    int choice;

    num = 21;

    do
    {
        printf("Remaining matchsticks: %d\n", num);
        printf("Pick a number among 1, 2, 3, 4:\n");
        scanf(" %d", &choice);

        if (!valid(choice, num))
        {
            printf("Invalid number of matchsticks.\n");
            continue;
        }

        int cc = 5 - choice;
        if (num > 4)
            printf("Computer's choice: %d\n\n", cc);

        num -= cc + choice;
    }
    while (num > 0);

    printf("Game over. Sorry, you lost."); // What arrogance! No code if computer lost!
    return 0;
}
