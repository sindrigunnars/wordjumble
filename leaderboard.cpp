#include <iostream>
#include <fstream>
#include <string.h>
#include "leaderboard.h"

using namespace std;

Score::Score() {
    name = new char[32];
}

ifstream& operator>>(ifstream& in, Score& score){
    in >> score.name >> score.score;
    return in;
}
ofstream& operator<<(ofstream& out, Score& score){
    out << score.name << " " << score.score << "\n";
    return out;
}

Leaderboard::Leaderboard() {
    capacity = 2;
    size = 0;
    scores = new Score[capacity];
}

Score Leaderboard::operator[](int idx) {
    return scores[idx];
}

void Leaderboard::addScore(const Score& score) {
    if (size == capacity) {resize();}
    int idx = 0;
    for (; idx < size; idx++) {
        if (scores[idx].score < score.score) {break;}
    }
    for (int i = size-1; idx <= i; i--) {
        scores[i+1] = scores[i];
    }
    scores[idx] = score;
    size++;
}
void Leaderboard::top5(){
    if (size <= 5) {all();}
    else{
        cout << "Top 5:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "\t" << i+1 << " - " << scores[i].name << ": " << scores[i].score << endl;
        }
    }
}

void Leaderboard::all() {
    cout << "Leaderboard: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "\t" << i+1 << " - " << scores[i].name << ": " << scores[i].score << endl;
    }
}

void Leaderboard::resize(){
    Score *tmp_arr = new Score[capacity * 2];
    for(int i = 0; i < size; i++){
        tmp_arr[i] = scores[i];            
    }
    delete[] scores;
    scores = tmp_arr;
    capacity *= 2;
}