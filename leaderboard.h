#ifndef LEADERBOARD_92836423
#define LEADERBOARD_92836423
#include <iostream>
#include <fstream>
using namespace std;

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

#endif //LEADERBOARD_92836423