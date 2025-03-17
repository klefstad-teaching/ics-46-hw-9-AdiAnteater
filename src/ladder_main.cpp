#include "ladder.c"

int main()
{
    set<string> word_list;
    load_words(word_list, "words.txt");

    string start, end;
    cout << "Enter start word: ";
    cin >> start;
    cout << "Enter end word: ";
    cin >> end;

    vector<string> ladder = generate_word_ladder(start, end, word_list);
    print_word_ladder(ladder);

    return 0;
}