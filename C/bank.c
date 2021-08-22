/* bank.c

   This program serves as a database
   for customers of a bank.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>

struct customer
{
    int acct_number;
    char name[25];
    int balance;
};

void input_customer(struct customer *s)
{
    printf("Account No.: ");
    scanf("%d", &(s->acct_number));
    fflush(stdin);

    printf("Name       : ");
    gets(s->name);
    fflush(stdin);

    printf("Balance    : ");
    scanf("%d", &(s->balance));
    fflush(stdin);
    printf("\n");
}

void print_struct(struct customer *s)
{
    printf("Account No.: %d\n", s->acct_number);
    printf("Name       : %s\n", s->name);
    printf("Balance    : Rs. %d\n\n", s->balance);
}

void print_details(struct customer *c, int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("Details of customer %d...\n", i+1);
        print_struct(c+i);
    }
}

void add_customer(struct customer *c, int *l)
{
    ++*l;
    c = realloc(c, *l * sizeof(struct customer));
    input_customer(c + *l - 1);
}

int find_customer(struct customer *c, int l, int acct_no)
{
    int index = -1;
    for (int i = 0; i < l; i++)
    {
        if ((c+i)->acct_number == acct_no)
        {
            index = i;
            break;
        }
    }
    return index;
}

void remove_customer(struct customer *c, int *l, int acct_no)
{
    int index = find_customer(c, *l, acct_no);
    if (index == -1)
    {
        printf("No such customer exists in the database.\n");
        return;
    }

    for (int i = index; i < *l - 1; i++)
        *(c + i) = *(c + i + 1);
    --*l;
}

void withdraw_amount(struct customer *c, int l, int acct_no)
{
    int index = find_customer(c, l, acct_no);
    if (index == -1)
    {
        printf("No such customer exists in the database.\n");
        return;
    }

    struct customer cust = *(c + index);
    int amt;
    printf("Available balance: Rs. %d\n", cust.balance);
    printf("How much money should be withdrawn? ");
    scanf("%d", &amt);
    fflush(stdin);

    if (cust.balance - amt >= 100)
    {
        (c + index)->balance -= amt;
        printf("\nYou withdrew Rs. %d.\n", amt);
        printf("Available balance: Rs. %d\n", (c + index)->balance);
    }
    else
        printf("Insufficient balance.\n");
}

void deposit_amount(struct customer *c, int l, int acct_no)
{
    int index = find_customer(c, l, acct_no);
    if (index == -1)
    {
        printf("No such customer exists in the database.\n");
        return;
    }

    struct customer cust = *(c + index);
    int amt;
    printf("Available balance: Rs. %d\n", cust.balance);
    printf("How much money should be deposited? ");
    scanf("%d", &amt);

    (c + index)->balance += amt;
    printf("\nYou deposited Rs. %d.\n", amt);
    printf("Available balance: Rs. %d\n", (c + index)->balance);
}

int main()
{
    int l;
    int ch;
    int acct_no;

    struct customer *c;

    l = 0;
    c = malloc(sizeof(struct customer));

    printf("-----Banking System-----\n");

    do
    {
        printf("What do you want to do?\n");
        printf("1. Display details of all customers\n");
        printf("2. Add a new customer\n");
        printf("3. Remove a customer\n");
        printf("4. Withdraw amount\n");
        printf("5. Deposit amount\n");
        printf("6. Quit\n");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch)
        {
            case 1: if (l == 0)
                    {
                        printf("There are no customers in the bank.\n");
                        break;
                    }
                    print_details(c, l);
                    break;
            case 2: printf("\nAdding details for customer %d...\n", l+1);
                    add_customer(c, &l);
                    break;
            case 3: if (l == 0)
                    {
                        printf("There are no customers in the bank.\n");
                        break;
                    }

                    printf("Enter account number: ");
                    scanf("%d", &acct_no);
                    fflush(stdin);

                    remove_customer(c, &l, acct_no);
                    break;
            case 4: if (l == 0)
                    {
                        printf("There are no customers in the bank.\n");
                        break;
                    }
                    printf("Enter account number: ");
                    scanf("%d", &acct_no);
                    fflush(stdin);

                    withdraw_amount(c, l, acct_no);
                    break;
            case 5: if (l == 0)
                    {
                        printf("There are no customers in the bank.\n");
                        break;
                    }
                    printf("Enter account number: ");
                    scanf("%d", &acct_no);
                    fflush(stdin);

                    deposit_amount(c, l, acct_no);
                    break;
            default: break;
        }
        printf("\n");
    } while (ch != 6);
}

