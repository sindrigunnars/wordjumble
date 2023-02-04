#include <iostream>
#include <fstream>
#include <string.h>

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
        cout << words[i].word << ": " << words[i].length << endl;
    }

    delete[] words;
    return 0;
}