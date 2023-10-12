#include<stdio.h>
#include <string.h>
#define MAX_USERS 20
#define UserOrPass_Len 50


char Users[MAX_USERS][UserOrPass_Len];
char Passwords[MAX_USERS][UserOrPass_Len];

int userCount = 0;

void Register() {
    if (userCount < MAX_USERS) {
        printf("Enter a username: ");
        scanf("%s", Users[userCount]);
        printf("Enter a password: ");
        scanf("%s", Passwords[userCount]);
        userCount++;
        printf("\n==========================\n");
        printf("Registration successful!\n");
        printf("==========================\n");
    } else {
        printf("\n==========================\n");
        printf(" Cannot register more users.\n");
        printf("==========================\n");
    }
}
int Login(char *username,char *password){
    for(int i=0;i<userCount;i++){
        if(strcmp(username,Users[i])==0&&strcmp(Passwords,Passwords[i])==0)
            return 1;
    }
    return 0;
}

int main() {
    int choice;
    char username[UserOrPass_Len];
    char password[UserOrPass_Len];

    while (1) {
        printf("\n1. Register\n2. Login\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Register();
                break;
            case 2:
                    printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                if (Login(username, password)) {
                    printf("\n=================\n");
                    printf("Login successful!\n");
                    printf("=================\n");
                } else {
                    printf("\n====================================================\n");
                    printf("Login failed. Username Or Password Wrong.\n");
                    printf("====================================================\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. \n");
        }
    }

    return 0;
}
