#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

namespace Utils {
    class FileUtil {
        public:
            ifstream inFile;
            vector<string> words{};
            string x;
            vector<string> get_content(string filename) {
                vector<string> content = read(filename);
                return content;
            }
        private:
            vector<string> read(string filename) {
                inFile.open(filename);
                if (!inFile) {
                    cout << "Unable to open file";
                    exit(1); // terminate with error
                }
                
                while (inFile >> x) {
                    words.push_back(x);
                }
                return words;
                inFile.close();
            }
    };
}

