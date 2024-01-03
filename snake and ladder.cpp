#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 // Board size

// Function to check for snakes and ladders
int checkSnakesAndLadders(int position) {
    switch (position) {
        case 3:
            return 17;
        case 7:
            return 11;
        case 19:
            return 5;
        case 27:
            return 1;
        case 21:
            return 9;
        case 50:
            return 3;
        case 54:
            return 33;
        case 62:
            return 19;
        case 70:
            return 89;
        case 81:
            return 24;
        case 87:
            return 51;
        case 92:
            return 73;
        case 95:
            return 75;
        case 98:
            return 80;
        default:
            return position;
    }
}

// Function to roll a dice
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to play the game
void playGame() {
    int player1 = 0, player2 = 0, currentPlayer = 1, dice, newPosition;
    srand(time(NULL));

    while (player1 < SIZE && player2 < SIZE) {
        printf("Player %d, press enter to roll the dice.\n", currentPlayer);
        getchar(); // Wait for user input

        dice = rollDice();
        printf("Player %d rolled a %d.\n", currentPlayer, dice);

        newPosition = currentPlayer == 1 ? player1 + dice : player2 + dice;
        newPosition = checkSnakesAndLadders(newPosition);

        if (currentPlayer == 1)
            player1 = newPosition;
        else
            player2 = newPosition;

        printf("Player 1 is at position %d, Player 2 is at position %d.\n", player1, player2);

        if (newPosition == SIZE) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        }

        // Change the turn
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

// Main function
int main() {
    printf("Welcome to Snake and Ladder Game!\n");
    playGame();
    return 0;
}












