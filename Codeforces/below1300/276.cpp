// Little Girl and Game

/*
string s, lowercase english letters

Players move in turns; 
one player can remove an arbitrary letter from s
, if the player can reorder the letters to get a palindrome, the player wins
*/

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

string getWinner(bool who) {
    if (who == true) {
        return "First";
    }
    return "Second";
}

int main() {
    unordered_map<char, int> freq{};
    int odd{};
    string s;
    cin >> s;
    for (char c: s) {
        freq[c]++;
    }

    int odd = 0;

    for (auto [key, value]: freq)
    {
        if (value % 2 == 1)
            ++odd;
    }

    if (odd == 0 || odd % 2 == 1)
        cout << "First";
    else
        cout << "Second";
}