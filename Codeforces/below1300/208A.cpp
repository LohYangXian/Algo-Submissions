#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string res;
    string word;
    cin >> word;
    vector<string> words;

    size_t pos; 
    while ((pos = word.find("WUB")) != string::npos) {
        word.replace(pos, 3, " ");
    }
    stringstream ss{word};
    while (ss >> word) {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) {
            res += ' ';
        }
        res += words[i];
    }

    cout << res;
}