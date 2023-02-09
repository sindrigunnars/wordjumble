#ifndef ALL_WORDS_92836423
#define ALL_WORDS_92836423
#include <iostream>
#include <fstream>
using namespace std;

struct WordHolder{
        int length, times_unshuffled;
        char* word;
        char* shuffled;
        WordHolder();
        friend ostream& operator<<(ostream& out, const WordHolder& word);
        friend ifstream& operator>>(ifstream& in, WordHolder& word);
        void shuffle();
        void unshuffle();

};

class AllWords{
    public:
        AllWords();

        void addWord(const WordHolder& wrd);
        int getSize();
        WordHolder getWord(int idx);

        friend ostream& operator<<(ostream& out, const AllWords& words);
        WordHolder operator[](int idx);

        virtual ~AllWords();

    private:
        int capacity, size;
        WordHolder *words;
        void resize();
};


struct Score {
    int score;
    char* name;
    Score();
    friend ifstream& operator>>(ifstream& in, Score& score);
    friend ofstream& operator<<(ofstream& out, Score& score);
};

class Leaderboard{
    public:
        Leaderboard();

        void addScore(const Score& score);
        void top5();
        void all();

        Score operator[](int idx);

    private:
        int capacity, size;
        Score *scores;
        
        void resize();
};

#endif //STAT_LIST_92836423