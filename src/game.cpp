#include <iostream> /*lib de I/O*/
#include <cstdlib>
using namespace std;



void println(string value) { 
    cout << value << endl;
}

namespace Game {
    class HangmanGame {
        public:
            void play() {
                println("Hello world - HangmanGame");
            }
    };
}