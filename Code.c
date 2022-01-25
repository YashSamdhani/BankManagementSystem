#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char names[10][100] = {"Yashowardhan Samdhani","Aditya Krishnan","Siddhanth Vashistha",
        "Bhavishya Pattanayak","Ananya Guatam","Aashriya Bhullar","Abir Majumder",
        "Amaan Majid","Animesh Gupta","Jaswanth Sunkara"};
int passwords[10] = {5915,5815,6489,3816,1895,9889,4826,4826,1568,1235}, flag[10];
long int debit_card_numbers[10] = {687942415726,917429365599,710573661154,971998449229,
        792087236336,984068812506,175584159453,959305088852,959305088852,
        744717302642}, balance[10] = {894418,8948,4589,489544,898489,89489,561598,589815,4898516,5918945};

void withdraw(int user)
{
    
    if(flag[user]>3)
        printf("Credit transactions unavailable\n\n");
    else
    {
        int amount;
        printf("Input the amount to be withdrawn: ");
        scanf("%d",&amount);
        
        if(amount > balance[user]-5000)
            printf("Invalid amount\n\n");
        else
        {
            balance[user] = balance[user] - amount;
            printf("Rs. %d credited.\nNew balance: %ld\n\n", amount, balance[user]);
        }
    }
}

void deposit(int user)
{
    if(flag[user]>3)
        printf("Debit transactions unavailable\n\n");
    else
    {
        int amount;
        printf("Input the amount to be deposited: ");
        scanf("%d",&amount);
        if(amount > 99999)
        {
            printf("The amount you are trying to deposit is higher than the usual amount.\n");
            printf("The debit transaction has been flagged.\n\n");
            flag[user]++;
        }
        
        if(flag[user]>3)
            printf("The debit transaction was unsuccessful");
        else
        {
            balance[user] = balance[user] + amount;
            printf("Rs. %d Debited.\nNew balance: %ld\n\n", amount, balance[user]);
        }
    }
}

void view_details(int user)
{
    long i;
    printf("Printing details...\n\n");
    for(i=0;i<=100000000;i++);
    for(i=0;i<=100000000;i++);
    
    printf("%s\n", names[user]);
    printf("%ld\n", debit_card_numbers[user]);
    printf("%ld\n\n", balance[user]);
}

int security()
{
    int check = 0, i;
    char username[100];
    long int debit_card_number;
    int password;
    
    printf("Input Username: ");
    scanf("%[^\n]s",username);
    printf("Input Debit Card Number: ");
    scanf("%ld", &debit_card_number);
    printf("Input Password: ");
    scanf("%d", &password);
        
    for(i=0;i<10;i++)
    {
        if(strcmp(username,names[i]) == 0)
            check++;
        if(password == passwords[i])
            check++;
        if(debit_card_number == debit_card_numbers[i])
            check++;
        if(check==3)
            break;
        else
            check = 0;
    }
    
    if(check < 3)
    {
        printf("Invalid Username/Password/Debit Card Number");
        return -1;
    }
    else
    {
        printf("Successfully logged in\n\n");
        return i;
    }
}

void main()
{
    int cont = security();
    
    if(cont == -1)
        exit(0);
    else
        while(1)
        {
            printf("----------Menu----------\n");
            printf("1. Withdraw Amount\n");
            printf("2. Deposit Amount\n");
            printf("3. Check Details\n");
            printf("4. Log out and Exit\n");
            printf("------------------------\n");
            
            printf("\nEnter your choice: ");
            int choice;
            scanf("%d", &choice);
            
            switch(choice)
            {
                case 1:
                withdraw(cont);
                break;
                
                case 2:
                deposit(cont);
                break;
                
                case 3:
                view_details(cont);
                break;
                
                case 4:
                printf("Thank You, Hope to see you again next time!");
                exit(0);
                break;
                
                default:
                printf("Invalid Choice!\n\n");
                int i;
                for(i=0;i<=100000000;i++);
                for(i=0;i<=100000000;i++);
                break;
            }
        }
}
