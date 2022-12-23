#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_GUESSES 6

int main() {
  // The word to guess
  char word[] = "hangman";

  // The number of letters in the word
  int word_length = strlen(word);

  // The number of letters the player has guessed correctly
  int correct_guesses = 0;

  // The number of incorrect guesses the player has made
  int incorrect_guesses = 0;

  // The letters the player has guessed
  char guessed_letters[26] = {0};

  // The word with the unguessed letters replaced with underscores
  char display_word[word_length + 1];
  for (int i = 0; i < word_length; i++) {
    display_word[i] = '_';
  }
  display_word[word_length] = '\0';

  // The game loop
  while (correct_guesses < word_length && incorrect_guesses < MAX_GUESSES) {
    // Print the current state of the game
    printf("Word: %s\n", display_word);
    printf("Guesses: %d\n", incorrect_guesses);
    printf("Guessed letters: ");
    for (int i = 0; i < 26; i++) {
      if (guessed_letters[i] != 0) {
        printf("%c ", guessed_letters[i]);
      }
    }
    printf("\n");

    // Get a guess from the player
    char guess;
    printf("Enter a letter: ");
    scanf(" %c", &guess);

    // Check if the guess is correct
    bool correct = false;
    for (int i = 0; i < word_length; i++) {
      if (word[i] == guess) {
        correct_guesses++;
        display_word[i] = guess;
        correct = true;
      }
    }

    // Update the list of guessed letters
    guessed_letters[guess - 'a'] = guess;

    if (!correct) {
      incorrect_guesses++;
    }
  }

  // Print the final result
  if (correct_guesses == word_length) {
    printf("You win! The word was %s.\n", word);
  } else {
    printf("You lose. The word was %s.\n", word);
  }

  return 0;
}
