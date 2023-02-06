#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include "allwords.h"

using namespace std;

int main() {
    srand(time(NULL));
    ifstream fin;
    fin.open("words.txt", ios::in);
    AllWords words;

    do {
        WordHolder word;
        fin >> word;
        words.addWord(word);
    } while (!fin.eof());

    cout << "Welcome to word jumble!!" << endl;
    char *input = new char[128];
    int points = 10;
    int correct = 0;
    WordHolder shuffled_word = words.getWord(rand() % words.getSize());
    do {
        cout << "Jumbled word: " << shuffled_word  << endl;
        cout << "Your guess(lower case)\n\t(h) for hint\n\t(q) for quit: ";
        cin >> input;

        if (strcmp(input, "h") == 0) {
            shuffled_word.unshuffle();
            points--;
        }

        if (strcmp(shuffled_word.shuffled, shuffled_word.word) == 0) {
            cout << "OOPS!! Too many hints, the word was: " << shuffled_word.word << endl << endl;
            shuffled_word = words.getWord(rand() % words.getSize());
        }
        
        if (strcmp(input, shuffled_word.word) == 0) {
            cout << "Congrats!!" << endl << endl;
            correct++;
            shuffled_word = words.getWord(rand() % words.getSize());
        }

        if (points == 0) {
            cout << "Game Over!!" << endl << "You guessed " << correct << " words" << endl;
            break;
        }

    } while(strcmp(input, "q") != 0);

    return 0;
}