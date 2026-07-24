#include <stdio.h>

void displayMenu();

void displayBalance(float balance);

void showSuccessMessage();

void showFailureMessage();

int main()
{
    int choice;
    float balance = 500.00;
    float amount;

    int pin = 1234;
    int enteredPin;
    int attempts = 0;

    float transactions[10];
    int transactionCount = 0;


    // PIN Authentication

    while (attempts < 3)
     {
       printf("=======================================\n");
       printf("             ATM LOGIN\n");
       printf("=======================================\n");
       printf("Enter your 4-digit PIN: ");
       scanf("%d", &enteredPin);

       if (enteredPin == pin)
{
        printf("\nLogin Successful!\n");
        break;
    }

      attempts++;

      showFailureMessage();
      printf("Incorrect PIN!\n");
      printf("Remaining Attempts: %d\n", 3 - attempts);

      if (attempts == 3)
    {
        printf("\nYour card has been blocked.\n");
        return 0;
    }
}



    do
    {
        displayMenu();

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                displayBalance(balance);

                break;

            case 2:
                 printf("\nEnter amount to deposit: ₹");
                 scanf("%f", &amount);

                 if (amount > 0)
                {
                 balance += amount;

                 transactions[transactionCount] = amount;
                 transactionCount++;

                 showSuccessMessage();

                 printf("₹%.2f deposited successfully.\n", amount);
                 printf("Current Balance : ₹%.2f\n", balance);

                }
            else
                {
                 showFailureMessage();
                 printf("Reason : Invalid deposit amount.\n");
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
                showSuccessMessage();

                printf("Reason : Insufficient balance.\n");
               }
                else
               {
                balance -= amount;

                showSuccessMessage();

                printf("₹%.2f withdrawn successfully.\n", amount);
                printf("Current Balance : ₹%.2f\n", balance);

               }
                break;

            case 4:

                printf("\n=====================================\n");
                printf("      TRANSACTION HISTORY\n");
                printf("=====================================\n");

                for (int i = 0; i < transactionCount; i++)
              {
                printf("%d. ₹%.2f\n", i + 1, transactions[i]);
              }

                printf("=====================================\n");

                break;


            case 5:
                printf("\n=======================================\n");
                printf("   THANK YOU FOR USING ATM SIMULATOR\n");
                printf("        Have a Great Day!\n");
                printf("=======================================\n");
                break;

                default:
                printf("\nInvalid Choice!\n");
               }

    } while(choice != 5);

    return 0;
}

    void displayMenu()
{
    printf("\n=======================================\n");
    printf("        WELCOME TO ATM SIMULATOR\n");
    printf("=======================================\n");

    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Transaction History\n");
    printf("5. Exit\n");

    printf("=======================================\n");
    printf("Enter your choice: ");
}

    void displayBalance(float balance)
{
    printf("\n-------------------------------------\n");
    printf("      ACCOUNT INFORMATION\n");
    printf("-------------------------------------\n");
    printf("Current Balance : ₹%.2f\n", balance);
    printf("-------------------------------------\n");
}

void showSuccessMessage()
{
    printf("\n=====================================\n");
    printf("    TRANSACTION SUCCESSFUL\n");
    printf("=====================================\n");
}

void showFailureMessage()
{
    printf("\n=====================================\n");
    printf("      TRANSACTION FAILED\n");
    printf("=====================================\n");
}
