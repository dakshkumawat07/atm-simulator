#include <stdio.h>

int main()
{
    int choice;
    float balance = 500.00;
    float amount;
    do
    {
        printf("\n=================================\n");
        printf("        ATM Simulator\n");
        printf("=================================\n");

        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nCurrent Balance: ₹%.2f\n", balance);
                break;

            case 2:
                 printf("\nEnter amount to deposit: ₹");
    scanf("%f", &amount);

    if (amount > 0)
{
    balance += amount;

    printf("\n₹%.2f deposited successfully!\n", amount);
    printf("Current Balance: ₹%.2f\n", balance);
}
else
{
    printf("\nInvalid amount! Please enter an amount greater than ₹0.\n");
}
    break;

            case 3:

printf("\nEnter amount to withdraw: ₹");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nInvalid amount! Please enter an amount greater than ₹0.\n");
    }
    else if (amount > balance)
    {
        printf("\nInsufficient balance!\n");
    }
    else
    {
        balance -= amount;

        printf("\n₹%.2f withdrawn successfully!\n", amount);
        printf("Current Balance: ₹%.2f\n", balance);
    }
                break;

            case 4:
                printf("\nThank you for using our ATM!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}
