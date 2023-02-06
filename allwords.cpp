#include <iostream>
#include <fstream>
#include <string.h>
#include "allwords.h"
#define DEBUG false

using namespace std;

WordHolder::WordHolder() {
    word = new char[128];
    shuffled = new char[128];
}

ostream& operator<<(ostream& out, const WordHolder& word){
    if (DEBUG) {
        out << "W:" << word.word << " S:" << word.shuffled << endl;
    } else {
        out << "\n\t";
        for (int i = 0; i < word.length-1; i++) {
            out << word.shuffled[i] << "-";
        }
        out << word.shuffled[word.length-1] << endl << "\t";
        for (int i = 0; i < word.length-1; i++) {
            if (word.word[i] == word.shuffled[i]) {
                out << word.shuffled[i] << "-";
            } else {
                out << "X" << "-";
            }
        }
        if (word.word[word.length-1] == word.shuffled[word.length-1]) {
            out << word.shuffled[word.length-1] << endl;;
        } else {
            out << "X" << endl;
        }
        
    }
    return out;
}
ifstream& operator>>(ifstream& in, WordHolder& obj){
    in >> obj.word;
    obj.length = strlen(obj.word);
    obj.shuffle();
    return in;
}

void WordHolder::shuffle() {
    strcpy(shuffled, word);
    do {
        for (int j = 0; j < length; j++) {
            int place1 = rand() % length;
            int place2 = rand() % length;
            char temp = shuffled[place1];
            shuffled[place1] = shuffled[place2];
            shuffled[place2] = temp;
        }
    } while(strcmp(word, shuffled) == 0);
    bool flag = true;
    for (int i = 0; i < length; i++) {
        if (word[i] == shuffled[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {unshuffle();}
}

void WordHolder::unshuffle() {
    int new_shuffle;
    while (true) {
        new_shuffle = rand() % length;
        if ((word[new_shuffle] != shuffled[new_shuffle]) || (strcmp(word, shuffled) == 0)) {
            break;
        }
    }
    char correct = word[new_shuffle];
    for (int j = 0; j < length; j++) {
        if (correct == shuffled[j]) {
            shuffled[j] = shuffled[new_shuffle];
            shuffled[new_shuffle] = correct;
            break;
        }
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