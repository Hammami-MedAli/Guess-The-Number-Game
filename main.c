#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

int main()
{
    int guess = 0;
    srand(time(NULL));
    int min = 1;
    int max = 0;
    int tries = 0;
    char difficulty = '\0';
    char rematch = '\0';
    int maxtries = 0;
    char name[50];
    int losses = 0;
    int wins = 0;


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    Beep(600, 120);
    Beep(800, 120);
    Beep(1000, 180);
    printf("============================================\n");
    printf("       * GUESS THE NUMBER GAME *\n");
    printf("============================================\n\n");
    Sleep(2500);
    SetConsoleTextAttribute(hConsole, 7);
    printf(">>> Enter your username : ");
    scanf("%s",&name);
    SetConsoleTextAttribute(hConsole, 3);
    Sleep(1000);
    SetConsoleTextAttribute(hConsole, 5);
    printf("---------------------------------------------------------------------------\n");
    printf("Hello %s Choose your difficulty level and try to guess the number!\n",name);
    SetConsoleTextAttribute(hConsole, 5);
    printf("---------------------------------------------------------------------------\n\n");
    Beep(1000, 100);
    Beep(1300, 150);
    SetConsoleTextAttribute(hConsole, 7);
    do{
    do{
    Sleep(1500);
    printf("E : Easy\nN : Normal\nH : Hard\n");
    Sleep(750);
    printf(">>> Choose Your Difficulty Level : ");
    scanf(" %c",&difficulty);
    Sleep(1250);
    difficulty = toupper(difficulty);

    if (difficulty == 'E'){
        max = 20;
        maxtries = 10;
        SetConsoleTextAttribute(hConsole, 5);
        printf("--------------------------------------------------------------\n");
        SetConsoleTextAttribute(hConsole, 10);
        printf("Guess The Number , Difficulty : Easy . You Have %d Tries \n",maxtries);
        SetConsoleTextAttribute(hConsole, 5);
        printf("--------------------------------------------------------------\n");
        Beep(500, 150);
        Beep(700, 150);
        Beep(900, 200);
        Sleep(600);
        SetConsoleTextAttribute(hConsole, 7);
        Sleep(750);
    }
    else if (difficulty == 'N'){
        max = 50;
        maxtries = 7;
        SetConsoleTextAttribute(hConsole, 11);
        SetConsoleTextAttribute(hConsole, 5);
        printf("--------------------------------------------------------------\n");
        SetConsoleTextAttribute(hConsole, 3);
        printf("Guess The Number , Difficulty : Normal . You Have %d Tries \n",maxtries);
        SetConsoleTextAttribute(hConsole, 5);
        printf("--------------------------------------------------------------\n");
        Beep(500, 150);
        Beep(700, 150);
        Beep(900, 200);
        Sleep(600);
        SetConsoleTextAttribute(hConsole, 7);
        Sleep(750);
    }
    else if (difficulty == 'H'){
        max = 100;
        maxtries = 5;
        SetConsoleTextAttribute(hConsole, 5);
        printf("--------------------------------------------------------------\n");
        SetConsoleTextAttribute(hConsole, 12);
        printf("Guess The Number , Difficulty : Hard . You Have %d Tries \n",maxtries);
        SetConsoleTextAttribute(hConsole, 5);
        printf("--------------------------------------------------------------\n");
        Beep(500, 150);
        Beep(700, 150);
        Beep(900, 200);
        Sleep(600);
        SetConsoleTextAttribute(hConsole, 7);
        Sleep(750);
    }
    else {
        SetConsoleTextAttribute(hConsole, 4);
        printf("\nInvalid Choice !\n\n");
        Beep(400, 200);
        SetConsoleTextAttribute(hConsole, 7);
        Sleep(750);
    }
    }while (difficulty != 'E' && difficulty != 'N' && difficulty != 'H');


    int number = (rand() % (max - min + 1)) + min;

    do{
        printf(">>> Guess a number between %d and %d : ", min, max );
        if (scanf("%d", &guess) != 1) {
        Sleep(1000);
        SetConsoleTextAttribute(hConsole, 4);
        printf("Invalid input! Please enter a number.\n");
        Beep(400, 200);
        SetConsoleTextAttribute(hConsole, 7);
        while (getchar() != '\n');
            continue;
        }
        if (guess < min || guess > max) {
        SetConsoleTextAttribute(hConsole, 4);
        Sleep(1000);
        printf("Number out of range! Please enter between %d and %d.\n", min, max);
        Beep(500, 200);
        SetConsoleTextAttribute(hConsole, 7);
        continue;
        }
        Sleep(750);
        tries++;
        if (tries > maxtries ){
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            losses++;
            Beep(400, 300);
            Beep(300, 300);
            printf("You Lost ! The number was %d\n\n\n", number);
            SetConsoleTextAttribute(hConsole, 7);
            break;
        }
        else if (guess < number ){
            SetConsoleTextAttribute(hConsole, 14);
            Beep(800, 100);
            printf("Go Higher !\n");
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(400);
            printf("Your number of guesses is : %d\n",tries);
            SetConsoleTextAttribute(hConsole, 13);
            printf("\n==================================================\n\n");
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(500);
        }
        else if (guess > number ){
            SetConsoleTextAttribute(hConsole, 14);
            Beep(800, 100);
            printf ("Go Lower !\n");
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(400);
            printf("Your number of guesses is : %d\n",tries);
            SetConsoleTextAttribute(hConsole, 13);
            printf("\n==================================================\n\n");
            SetConsoleTextAttribute(hConsole, 7);
            Sleep(500);
        }
        else if (guess == number) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 10);
            Beep(1000, 150);
            Beep(1200, 150);
            Beep(1500, 200);
            Beep(1800, 250);
            printf("Congrats, You Won!\n");
            wins++;
            Sleep(1500);
            printf("----- Your Number Of Guesses was %d ----- \n\n\n" , tries);
            SetConsoleTextAttribute(hConsole, 7);
        }
    }while (guess != number);
    Sleep(1000);
    SetConsoleTextAttribute(hConsole, 8);
    printf(" You have %d Wins    |    You have %d losses \n\n",wins,losses);
    SetConsoleTextAttribute(hConsole, 7);
    Sleep (2000);
    printf("Y = Yes\nN = No\n");
    printf("Do you want to play again ? : ");
    scanf(" %c",&rematch);
    Sleep(1500);
    rematch=toupper(rematch);
    if (rematch == 'Y'){
        Beep(900, 100);
        Beep(1100, 150);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Cool ! Lets Play again .\n\n");
        SetConsoleTextAttribute(hConsole, 7);
    }
    tries = 0;
    }while (rematch == 'Y');
    Sleep(1000);
    SetConsoleTextAttribute(hConsole, 1);
    printf("Alright , Have a good day!");
    Beep(600, 200);
    Beep(500, 250);
    Beep(400, 300);
    SetConsoleTextAttribute(hConsole, 7);
}


