#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

struct WordHolder{
    int length;
    char* word;
};

int main() {
    ifstream fin;
    fin.open("words.txt", ios::in);

    WordHolder *words;
    words = new WordHolder[100];
    int numwrds = 0;
    do {
        words[numwrds].word = new char[128];
        fin >> words[numwrds].word;
        words[numwrds].length = strlen(words[numwrds].word);
        numwrds++;
    } while (!fin.eof());

    for (int i = 0; i < numwrds; i++) {
        srand(time(NULL));
        const int len = words[i].length;
        char shuffled[128];
        strcpy(shuffled, words[i].word);
        for (int j = 0; j < len; j++) {
            int place1 = rand() % len;
            int place2 = rand() % len;
            char temp = shuffled[place1];
            shuffled[place1] = shuffled[place2];
            shuffled[place2] = temp;
        }
        cout << words[i].word << ": " << shuffled << endl;
    }

    delete[] words;
    return 0;
}