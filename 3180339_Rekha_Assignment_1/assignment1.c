/*
 * Name of program: Assignment 1
 * Description: C program that picks a secret number between 1 and 10. 
 *              The user gets up to 3 tries to guess the number.
 * Inputs: User guess (integer) or letters
 * Output: Terminal prompts and feedback on the guesses
 * Collaborators: Saylor Statler
 * Other sources: ChatGPT, gemini
 * Author: Nivedita Rekha
 * Creation date: September 8 2026
 * Revision date: September 8 2026
 * Revisions: edited program so that it can handle invalid inputs 
 */
 #include <stdio.h>  // Includes the standard input/output library for printf(), scanf(), and getchar()

int main(void) {  // Starts the main function where the program begins

    const int secret = 7;  // Stores the secret number as a constant so it cannot be changed
    const int MAX_ATTEMPTS = 3;  // Stores the maximum number of attempts allowed
    int guess;  // Stores the user's guess
    int won = 0;  // Keeps track of whether the user correctly guessed the number
    int c;  // Stores characters temporarily when clearing invalid input

    printf("Guess a number between 1 and 10.\n");  // Displays instructions to the user

    // Repeats the guessing process for a maximum of three attempts
    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {

        // Displays the current attempt number and asks the user for a guess
        printf("Attempt %d/%d. Enter your guess: ", attempt, MAX_ATTEMPTS);

        // Checks whether the user entered a valid integer
        if (scanf("%d", &guess) != 1) {

            // Displays a message when the user enters invalid input
            printf("Invalid input. Please enter a number.\n");

            // Removes the invalid characters from the input buffer
            while ((c = getchar()) != '\n' && c != EOF) {
                // Continues clearing the input until the end of the line
            }

            // Skips the rest of this attempt and moves to the next attempt
            continue;
        }

        // Checks whether the user's guess matches the secret number
        if (guess == secret) {

            // Tells the user that their guess was correct
            printf("Correct! You win!\n");

            // Changes won to 1 to indicate that the user won
            won = 1;

            // Stops the loop because the user has won
            break;

        // Checks whether the user's guess is lower than the secret number
        } else if (guess < secret) {

            // Tells the user that their guess was too low
            printf("Too low! Try again.\n");

        // Runs when the user's guess is higher than the secret number
        } else {

            // Tells the user that their guess was too high
            printf("Too high! Try again.\n");
        }
    }

    // Checks whether the user did not correctly guess the secret number
    if (!won) {

        // Tells the user they lost and displays the secret number
        printf("Out of tries! The number was %d. You lose.\n", secret);
    }

    // Ends the program successfully
    return 0;
}
