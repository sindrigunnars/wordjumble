#include <iostream>
#include <string.h>
#include "allwords.h"

using namespace std;

WordHolder::WordHolder() {
    word = new char[128];
    shuffled = new char[128];
}

ostream& operator<<(ostream& out, const WordHolder& word){
    out << "W:" << word.word << " S:" << word.shuffled << " L:" << word.length << endl;
    return out;
}

void WordHolder::shuffle() {
    strcpy(shuffled, word);
    for (int j = 0; j < length; j++) {
        int place1 = rand() % length;
        int place2 = rand() % length;
        char temp = shuffled[place1];
        shuffled[place1] = shuffled[place2];
        shuffled[place2] = temp;
    }
}

AllWords::AllWords() {
    capacity = 2;
    size = 0;
    words = new WordHolder[capacity];
}

void AllWords::addWord(const WordHolder& wrd) {
    if (size == capacity) {resize();}
    words[size] = wrd;
    size++;
}

int AllWords::getSize() {
    return size;
}

WordHolder AllWords::getWord(int idx) {
    return words[idx];
}

ostream& operator<<(ostream& out, const AllWords& words){
    for(int i = 0; i < words.size; i++){
        out << words.words[i];
    }
    return out;
}

WordHolder AllWords::operator[](int idx) {
    return words[idx];
}

AllWords::~AllWords(){
    delete[] words;
}

void AllWords::resize() {
    for (int i = 0; i < size; i++) {
    }
    WordHolder *tmp_arr = new WordHolder[capacity * 2];
    for(int i = 0; i < size; i++){
        tmp_arr[i] = words[i];            }
    delete[] words;
    words = tmp_arr;
    capacity *= 2;
}