#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "allwords.h"
#include "leaderboard.h"

using namespace std;

int main() {
    srand(time(NULL));
    ifstream fin;
    ofstream fout;
    fout.open("leaderboard.txt", ios_base::app);
    fin.open("words.txt", ios::in);
    AllWords words;

    do {
        WordHolder word;
        fin >> word;
        words.addWord(word);
    } while (!fin.eof());

    char *choice = new char[128];

    do {
        cout << "\nWelcome to word jumble!!\n\tPress (p) to play:\n\tPress (l) for leaderboeard:\n\tPress (q) to quit:" << endl;
        cin >> choice;
        if (strcmp(choice, "p") == 0) {
            int points = 11;
            int correct = 0;
            char *input = new char[128];
            WordHolder shuffled_word = words.getWord(rand() % words.getSize());
            time_t end, begin;
            time(&begin);
            do {
                cout << "\nJumbled word: " << shuffled_word  << endl;
                cout << "You have " << points - 1 << " hints left" << endl;
                cout << "Your guess(lower case)\n\t(h) for hint:";
                cin >> input;

                if (strcmp(input, "h") == 0) {
                    shuffled_word.unshuffle();
                    points--;
                }

                if (strcmp(shuffled_word.shuffled, shuffled_word.word) == 0) {
                    cout << "\nOOPS!! Too many hints, the word was: " << shuffled_word.word << endl << endl;
                    points++;
                    shuffled_word = words.getWord(rand() % words.getSize());
                }
                
                if (strcmp(input, shuffled_word.word) == 0) {
                    cout << "\nCongrats!!" << endl;
                    correct++;
                    shuffled_word = words.getWord(rand() % words.getSize());
                }

                if (points == 0) {
                    time(&end);
                    int score;
                    int diff = (int)(end - begin);
                    if (diff < 10) {diff = 10;}
                    if (correct < 1) {score = 0;}
                    else {score = (int)(correct*10) / (diff/10);}

                    cout << "\nGame Over!!" << endl << "You guessed " << correct << " words in " << diff << " seconds" << endl;
                    cout << "Your score is " << score << endl;
                    char *name = new char[32];
                    cout << "Enter your name (no spaces): ";
                    cin >> name;
                    Score savescore;
                    savescore.name = name;
                    savescore.score = score;
                    fout << savescore;
                    fout.close();
                    break;
                }

            } while(true);
        }
        if (strcmp(choice, "l") == 0) {
            ifstream fin1;
            fin1.open("leaderboard.txt", ios::in);
            Leaderboard lead;

            while (true){
                Score score;
                fin1 >> score;
                if (fin1.eof()) {break;}
                lead.addScore(score);
            }
            fin1.close();
            cout << "\tPress (t) for top 5:\n\tPress (a) for all:" << endl;
            cin >> choice;
            if (strcmp(choice, "t") == 0) {lead.top5();}
            else if (strcmp(choice, "a") == 0) {lead.all();}
        }

    } while(strcmp(choice, "q") != 0);
    fin.close();
    return 0;
}