#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include "allwords.h"

using namespace std;

int main() {
    ifstream fin;
    fin.open("words.txt", ios::in);
    AllWords words;

    do {
        WordHolder word;
        fin >> word.word;
        word.length = strlen(word.word);
        words.addWord(word);
    } while (!fin.eof());

    srand(time(NULL));

    for(int i = 0; i < words.getSize(); i++) {
        words[i].shuffle();
    }
    cout << words;
    return 0;
}