#include <iostream> /*lib de I/O*/
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include "./utils/fileUtil.cpp"

using namespace std;
using namespace Utils;


void println(string value) { 
    cout << value << endl;
}

namespace Game {
    class HangmanGame {
        public:
            char current_guess;
            string attempted_letters = "";
            string guessed_letters = "";
            bool isHanged = false;
            bool debug = true;
            bool won = false;
            int lives = 9;   /*Head, Two eyes, mouth, body, 2 arms & two legs*/

            string secret_word = get_secret_word();
            void play() {
                println("\n*****************************");
                println("*  Welcome to Hangman Game  *");
                println("*****************************");
                if(debug) {
                    println("[DEBUG] Secret word: " + secret_word);
                }
                while (!won && !isHanged) {
                    guess();
                }
                if (won) {
                    println("\n**************");
                    println("*  WINNER!!  *");
                    println("**************");
                    cout << "You won! The secret word was: " + secret_word +  "\nyou remained with " << lives << " lives. \nCongratulations!" << endl;
                } else {
                    println("\n***************");
                    println("*  GAME OVER  *");
                    println("***************");
                    println("Oh no! You lose! The secret word was: " + secret_word + ". Try again?");
                }
            }
        private:
            /* # TODO: Criar vetor Chutopu */ 
            string  get_secret_word() {
                FileUtil words;
                vector<string> word_list = words.get_content("./src/data/wordlist.txt");
                int random_index = rand() % word_list.size();
                return word_list[random_index];
            }
            void guess() {
                cout << "\nLives: " << lives << " - Guessed Right: " << guessed_letters << " - Attempted: " << attempted_letters << endl;
                cout << "\nGuess a letter: ";
                cin >> current_guess;
                check_already_attempted_letters();
            }
            void validate_guessed_letters() {
                if (secret_word.find(current_guess) != string::npos) {
                    guessed_letters += current_guess;
                    println("You guessed it right!");
                    attempted_letters += current_guess;
                } else {
                    println("Wrong letter, try again!");
                    attempted_letters += current_guess;
                    lives--;
                }
                check_game_status();
            }
            void check_already_attempted_letters() {
                if (attempted_letters.find(current_guess) != string::npos) {
                    println("You already guessed that letter");
                } else {
                    validate_guessed_letters();
                }
            }
            
            bool contains_all_characters( const std::string &str, const std::string &prt )
            {
                for ( char c : prt )
                {
                    if ( str.find( c ) == std::string::npos )
                    {
                        return false;
                    }
                }

                return true;
            }

            void check_game_status() {
                won = contains_all_characters(guessed_letters, secret_word);
                isHanged = lives == 0;
            }
    }; 
}