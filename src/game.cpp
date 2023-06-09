#include <iostream> /*lib de I/O*/
#include <cstdlib>
#include <string>

using namespace std;



void println(string value) { 
    cout << value << endl;
}

namespace Game {
    class HangmanGame {
        public:
            string current_guess = "";
            string attempted_letters = "";
            string guessed_letters = "";
            bool isHanged = false;
            bool won = false;
            int guesses = 0;

            string secret_word = "MELON";
            void play() {
                println("Hello world - HangmanGame " + secret_word);
                while (!won && !isHanged) {
                    guess();
                }
            }
        private:
            void guess() {
                cout << "Guess a letter: ";
                cin >> current_guess;
                if (current_guess.length() != 1) {
                    println("Please guess a single letter");
                    return;
                }
                if (attempted_letters.find(current_guess) != string::npos) {
                    println("You already guessed that letter");
                    return;
                }
                if (secret_word.find(current_guess) != string::npos) {
                    guessed_letters += current_guess;
                    println("You guessed a letter");
                } else {
                    guesses++;
                    println("You guessed a wrong letter");
                }
                attempted_letters += current_guess;
            }
    };
}