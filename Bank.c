// Bank Management system
// Developed by Lakshay 2K20/SE/77

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i, j;
int main_exit;
void menu();
struct date
{
    int month, day, year;
};
struct
{
    char name[60];
    int acc_no, age;
    char address[60];
    char aadhar[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
 
} add, upd, check, rem, transaction;
 
float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);
}
void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}
 
void new_acc()
 
{
    int choice;
    FILE *ptr;
 
    ptr = fopen("record.txt", "a+");
account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2  ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's Date(mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("\nEnter the Account Number:");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter the Customer Name : ");
    scanf("%s", add.name);
    printf("\nEnter the Date of Birth(mm/dd/yyyy) : ");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the Age : ");
    scanf("%d", &add.age);
    printf("\nEnter the Address : ");
    scanf("%s", add.address);
    printf("\nEnter the Aadhar number : ");
    scanf("%s", add.aadhar);
    printf("\nEnter the Phone Number : ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit in Rupees : Rs ");
    scanf("%f", &add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice : ");
    scanf("%s", add.acc_type);
    fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
 
    fclose(ptr);
    printf("\nAccount created successfully!");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit : ");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}
void view_list()
{
    FILE *view;
    view = fopen("record.txt", "r");
    int test = 0;
    system("cls");
    printf("\nACC. NO.\t\tNAME\t\t\t    ADDRESS\t\tPHONE\n");
 
    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }
 
    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }
 
view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}
void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.txt", "r");
    newrec = fopen("new.txt", "w");
 
    printf("\nEnter the account no. of the customer whose info you want to change : ");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter the new address:");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.aadhar, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
            else if (choice == 2)
            {
                printf("Enter the new phone number:");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt", "record.txt");
 
    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
 
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}
void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.txt", "r");
    newrec = fopen("new.txt", "w");
 
    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmpi(add.acc_type, "fixed1") == 0 || strcmpi(add.acc_type, "fixed2") == 0 || strcmpi(add.acc_type, "fixed3") == 0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit:Rs ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw : Rs ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt", "record.txt");
    if (test != 1)
    {
        printf("\n\nRecord not found!!");
    transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 0)
            transact();
        else if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}
void erase(void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.txt", "r");
    newrec = fopen("new.txt", "w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
 
        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt", "record.txt");
    if (test == 0)
    {
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
 
        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit : ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else
            close();
    }
}
 
void see(void)
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    ptr = fopen("record.txt", "r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the account number : ");
        scanf("%d", &check.acc_no);
 
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("cls");
                test = 1;
 
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nAadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rs %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs%.2f as interest on %d/%d/%d\n", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs.%.2f as interest on %d/%d/%d\n", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs.%.2f as interest on %d/%d/%d\n", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs.%.2f as interest on %d of every month\n", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {
 
                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    else if (choice == 2)
    {
        printf("Enter the name:");
        scanf("%s", &check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.aadhar, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmpi(add.name, check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \naadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rs%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.aadhar, add.phone,
                       add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmpi(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\nYou will get Rs.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "current") == 0)
                {
 
                    printf("\nYou will get no interest\a\a");
                }
            }
        }
    }
 
    fclose(ptr);
    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu();
        else if (main_exit == 2)
            close();
        else if (main_exit == 0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
    }
    if (main_exit == 1)
    {
        system("cls");
        menu();
    }
 
    else
    {
        system("cls");
        close();
    }
}
void encrypt(void)
{
    FILE *fps, *fpt;
    char ch;
    fps = fopen("record.txt", "r");
    if (fps == NULL)
    {
        printf("Error 1 in Encrypting records\n");
    }
    fpt = fopen("temp1.txt", "w");
    if (fpt == NULL)
    {
        printf("Error 2 in Encrypting records\n");
    }
    ch = fgetc(fps);
    while (ch != EOF)
    {
        ch = ch + 100;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen("record.txt", "w");
    if (fps == NULL)
    {
        printf("Error 3 in Encrypting records\n");
    }
    fpt = fopen("temp1.txt", "r");
    if (fpt == NULL)
    {
        printf("Error 4 in Encrypting records\n");
    }
    ch = fgetc(fpt);
    while (ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
}
void decrypt(void)
{
    char ch, ch1;
    FILE *fps, *fpt;
    fps = fopen("record.txt", "r");
    ch1 = fgetc(fps);
    if (ch1 != EOF)
    {
        fclose(fps);
        fps = fopen("record.txt", "w");
        if (fps == NULL)
        {
            printf("Error 1 in decrypting records\n");
        }
        fpt = fopen("temp1.txt", "r");
        if (fpt == NULL)
        {
            printf("Error 2 in decrypting records\n");
        }
        ch = fgetc(fpt);
        while (ch != EOF)
        {
            ch = ch - 100;
            fputc(ch, fps);
            ch = fgetc(fpt);
        }
        fclose(fps);
        fclose(fpt);
    }
    fclose(fps);
}
void encryptt()
{
    char ch;
    FILE *fps, *fpt;
    fps = fopen("security.txt", "r");
    if (fps == NULL)
    {
        printf("Error");
    }
    fpt = fopen("temp2.txt", "w");
    if (fpt == NULL)
    {
        printf("Error");
    }
    ch = fgetc(fps);
    if (ch != EOF)
    {
        while (ch != EOF)
        {
            ch = ch + 100;
            fputc(ch, fpt);
            ch = fgetc(fps);
        }
        fclose(fps);
        fclose(fpt);
        fps = fopen("security.txt", "w");
        if (fps == NULL)
        {
            printf("Error");
        }
        fpt = fopen("temp2.txt", "r");
        if (fpt == NULL)
        {
            printf("Error");
        }
        ch = fgetc(fpt);
        while (ch != EOF)
        {
            ch = fputc(ch, fps);
            ch = fgetc(fpt);
        }
    }
    fclose(fps);
    fclose(fpt);
}
void decryptt()
{
    char ch, ch1;
    FILE *fps = NULL, *fpt = NULL, *fps1 = NULL;
    fps1 = fopen("security.txt", "r");
    ch1 = fgetc(fps1);
    if (ch1 == EOF)
    {
        goto end;
    }
    else
    {
        fps = fopen("security.txt", "w");
        if (fps == NULL)
        {
            printf("Error");
        }
        fpt = fopen("temp2.txt", "r");
        if (fpt == NULL)
        {
            printf("Error");
        }
        ch = fgetc(fpt);
        while (ch != EOF)
        {
            ch = ch - 100;
            fputc(ch, fps);
            ch = fgetc(fpt);
        }
        fclose(fps);
        fclose(fpt);
    }
end:
    fclose(fps1);
}
void pswrd()
{
    FILE *fk = NULL, *tk = NULL;
    char str1[10], str2[10], pass[10], pas[10];
    printf("Enter the old password : ");
    scanf("%s", pass);
    tk = fopen("security.txt", "r");
    fscanf(tk, "%s", pas);
    fclose(tk);
    if (strcmp(pas, pass) == 0)
    {
        system("cls");
    kik:
        printf("Format of Password......\n1. 8 characters\n2. Contains atleast one Special character ($,*,&,^,#,@)\n");
        printf("\nEnter the New Password : ");
        scanf("%s", str1);
        printf("\nConfirm New Password : ");
        scanf("%s", str2);
        if (strcmp(str1, str2) == 0)
        {
            if (strlen(str1) == 8)
            {
                if (str1[0] == '@' || str1[0] == '$' || str1[0] == '*' || str1[0] == '&' || str1[0] == '^' || str1[0] == '#' ||
                    str1[1] == '@' || str1[1] == '$' || str1[1] == '*' || str1[1] == '&' || str1[1] == '^' || str1[1] == '#' ||
                    str1[2] == '@' || str1[2] == '$' || str1[2] == '*' || str1[2] == '&' || str1[2] == '^' || str1[2] == '#' ||
                    str1[3] == '@' || str1[3] == '$' || str1[3] == '*' || str1[3] == '&' || str1[3] == '^' || str1[3] == '#' ||
                    str1[4] == '@' || str1[4] == '$' || str1[4] == '*' || str1[4] == '&' || str1[4] == '^' || str1[4] == '#' ||
                    str1[5] == '@' || str1[5] == '$' || str1[5] == '*' || str1[5] == '&' || str1[5] == '^' || str1[5] == '#' ||
                    str1[6] == '@' || str1[6] == '$' || str1[6] == '*' || str1[6] == '&' || str1[6] == '^' || str1[6] == '#' ||
                    str1[7] == '@' || str1[7] == '$' || str1[7] == '*' || str1[7] == '&' || str1[7] == '^' || str1[7] == '#')
                {
                    fk = fopen("security.txt", "w");
                    fputs(str1, fk);
                    fclose(fk);
                    printf("\nPassword Changed Successfully");
                    printf("\n\nEnter 1 to go to the main menu and 0 to exit : ");
                    scanf("%d", &main_exit);
                    system("cls");
                    if (main_exit == 1)
                    {
                        menu();
                    }
                    else
                    {
                        close();
                    }
                }
                else
                {
                    printf("\n\nPassword Must Contain Atleast One special Character($,*,&,^,#,@)");
                    goto kik;
                }
            }
            else
            {
                printf("\n\nPassword must be of Eight(8) Characters So, Plz Re-Enter the Password\n");
                goto kik;
            }
        }
        else
        {
            printf("New Password And Confirm Password Doesn't Matched\n");
            printf("Retry Again \n");
            goto kik;
        }
    }
    else
    {
        printf("Wrong Password\n");
        printf("Enter 1 to go to the main menu and 0 to exit : ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}
void close(void)
{
    printf("\n\n\n\nThis Project Banking Management System is developed by\n\xB2\xB2\xB2\xB2\xB2\xB2 LAKSHAY AND LAVISHA \xB2\xB2\xB2\xB2\xB2\xB2\n2k20/B8/57 and 2k20/b8/58\nThankyou.");
}
void menu(void)
{
    int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1. Create new account.\n\t\t2. Update information of existing account.\n\t\t3. For transactions.\n\t\t4. Check the details of existing account.\n\t\t5. Removing existing account.\n\t\t6. View customer's list.\n\t\t7. Change login Password.\n\t\t8. Log Out.\n\n\n\n\n\t\t Enter your choice : ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        pswrd();
        break;
    case 8:
        printf("\n\n\n\n\n\nLOGGING OFF");
        for (int i = 0; i < 10; i++)
        {
            fordelay(70000000);
            printf(".");
        }
        system("cls");
        close();
        break;
    default:
        system("cls");
        printf("Enter the vaild option\n\n");
        printf("Enter 1 to go to the main menu and 0 to exit : ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}
int main()
{
    FILE *secr = NULL;
    int i = 0;
    char c, str1[10], str2[10], data[10], pass[10], password[10];
    decrypt();
    decryptt();
    secr = fopen("security.txt", "r");
    fscanf(secr, "%s", data);
    fclose(secr);
    secr = fopen("security.txt", "r");
    if (secr == NULL)
    {
        system("cls");
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SETUP GUIDE \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    }
    c = fgetc(secr);
    if (c == EOF)
    {
        fclose(secr);
        printf("\n\nCreate a STRONG login Password of 8 characters(Containing atleast one Special character - $,*,&,^,#,@)\n");
    label:
        secr = fopen("security.txt", "w");
        printf("\nEnter the password : ");
        gets(str1);
        printf("\nConfirm your password : ");
        gets(str2);
        if (strcmp(str1, str2) == 0)
        {
            if (strlen(str1) == 8)
            {
                if (str1[0] == '@' || str1[0] == '$' || str1[0] == '*' || str1[0] == '&' || str1[0] == '^' || str1[0] == '#' ||
                    str1[1] == '@' || str1[1] == '$' || str1[1] == '*' || str1[1] == '&' || str1[1] == '^' || str1[1] == '#' ||
                    str1[2] == '@' || str1[2] == '$' || str1[2] == '*' || str1[2] == '&' || str1[2] == '^' || str1[2] == '#' ||
                    str1[3] == '@' || str1[3] == '$' || str1[3] == '*' || str1[3] == '&' || str1[3] == '^' || str1[3] == '#' ||
                    str1[4] == '@' || str1[4] == '$' || str1[4] == '*' || str1[4] == '&' || str1[4] == '^' || str1[4] == '#' ||
                    str1[5] == '@' || str1[5] == '$' || str1[5] == '*' || str1[5] == '&' || str1[5] == '^' || str1[5] == '#' ||
                    str1[6] == '@' || str1[6] == '$' || str1[6] == '*' || str1[6] == '&' || str1[6] == '^' || str1[6] == '#' ||
                    str1[7] == '@' || str1[7] == '$' || str1[7] == '*' || str1[7] == '&' || str1[7] == '^' || str1[7] == '#')
                {
                    printf("Password Created....!!\n");
                    fputs(str1, secr);
                    printf("\nRestart..! Your Program For Availing Banking Services\n");
                    fclose(secr);
                    encryptt();
                }
                else
                {
                    printf("\n\nPassword Must Contain Atleast One special Character($,*,&,^,#,@)");
                    goto label;
                }
            }
            else
            {
                printf("\n\nPlz Enter the password Of Eight(8) Characters\n");
                goto label;
            }
        }
        else
        {
            printf("\t\tThey must be Matched! Re-Enter the Password\n");
            goto label;
        }
    }
    else
    {
        system("cls");
    star:
        printf("\n\n\t\tEnter the password to login : ");
        scanf("%s", pass);
        strcpy(password, data);
        if (strcmp(pass, password) == 0)
        {
            printf("\n\nPassword Match!\nLOADING");
            for (i = 0; i <= 7; i++)
            {
                fordelay(70000000);
                printf(".");
            }
            system("cls");
            menu();
        }
        else
        {
            printf("\n\nWrong password :( \a\a\a");
        login_try:
            printf("\nEnter 1 to try again and 0 to exit : ");
            scanf("%d", &main_exit);
            if (main_exit == 1)
            {
                system("cls");
                goto star;
            }
            else if (main_exit == 0)
            {
                system("cls");
                close();
            }
            else
            {
                printf("\nInvalid!");
                fordelay(1000000000);
                system("cls");
                goto login_try;
            }
        }
        fclose(secr);
        encryptt();
    }
    encrypt();
    return 0;
}
