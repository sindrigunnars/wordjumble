#ifndef ALL_WORDS_92836423
#define ALL_WORDS_92836423

using namespace std;

struct WordHolder{
        int length;
        char* word;
        char* shuffled;
        WordHolder();
        friend ostream& operator<<(ostream& out, const WordHolder& word);
        void shuffle();

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
        int capacity;
        int size;
        WordHolder *words;
        void resize();
};

#endif //STAT_LIST_92836423