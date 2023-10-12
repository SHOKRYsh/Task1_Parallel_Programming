// Shokry Mansour Shokry
#include <stdio.h>
#include <string.h>

struct User {
    char email[50];
    char password[50];
};


void registerUser() {
    struct User user;
    printf("Enter your email: ");
    scanf("%s", user.email);
    printf("Enter your password: ");
    scanf("%s", user.password);

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening \n");
        return;
    }

    fprintf(file, "%s %s\n", user.email, user.password);
    fclose(file);
    printf("Registration successful\n");
}


int loginUser() {
    struct User user;
    printf("Enter your email: ");
    scanf("%s", user.email);
    printf("Enter your password: ");
    scanf("%s", user.password);

    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error opening\n");
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char savedEmail[50], savedPassword[50];
        sscanf(line, "%s %s", savedEmail, savedPassword);
        if (strcmp(user.email, savedEmail) == 0 && strcmp(user.password, savedPassword) == 0) {
            fclose(file);
            return 1; 
        }
    }

    fclose(file);
    return 0; 
}

int main() {
    int choice;
    printf("-----------------------------------------");
    printf("1. Register\n2. Login\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        if (loginUser()) {
            printf("Login successful \n");
        } else {
            printf("Login failed ,Incorrect email or password\n");
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
