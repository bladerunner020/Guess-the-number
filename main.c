#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of attempts allowed
#define MAX_ATTEMPTS 10

// ANSI escape code for yellow text
#define YELLOW "\033[93m"
// ANSI escape code to reset text attributes
#define RESET "\033[0m"

// Function to get user input for a guess
int getUserGuess() {
  int guess;
  // Prompt the user to enter a guess
  printf("Enter your guess: ");
  // Read the user's input as an integer
  scanf("%d", &guess);
  // Return the user's guess
  return guess;
}

int main() {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random number between 1 and 100
  int targetNumber = rand() % 100 + 1;
  int userGuess;
  int attempts = 0;

  // Display a welcome message with ANSI escape codes for formatting
  printf("🎉 Welcome to the Magical Number Guessing Adventure! 🎉\n");
  printf("Can you guess the secret number between 1 and 100?\n");
  // Display the number of attempts in yellow
  printf("You have " YELLOW "%d " RESET "attempts to unveil the mystery!\n",
         MAX_ATTEMPTS);

  // Start the game loop
  do {
    // Get the user's guess
    userGuess = getUserGuess();

    // Check if the guess is correct, too low, or too high
    if (userGuess == targetNumber) {
      // Display a congratulatory message with the number of attempts in yellow
      printf(
          "🌟 Congratulations! You've discovered the enchanted number in " YELLOW
          "%d " RESET "%s! 🌟\n",
          attempts + 1, attempts == 0 ? "attempt" : "attempts");
      // Exit the loop as the correct number is guessed
      break;
    } else if (userGuess < targetNumber) {
      // Display a message for a guess that is too low
      printf("🔮 Too low, brave adventurer. Seek a higher number! 🔮\n");
    } else {
      // Display a message for a guess that is too high
      printf("🔮 Too high, intrepid explorer. Choose a smaller number! 🔮\n");
    }

    // Increment the attempts counter
    attempts++;

    // Check if the maximum number of attempts is reached
    if (attempts == MAX_ATTEMPTS) {
      // Display a message for running out of attempts, revealing the correct
      // number in yellow
      printf(
          "⚠️ Oops! You've run out of attempts. The magical number was " YELLOW
          "%d" RESET ". Better luck next time! ⚠️\n",
          targetNumber);
      // Exit the loop
      break;
    }

  } while (1);  // Continue the loop until a correct guess or the maximum
                // attempts are reached

  return 0;
}
