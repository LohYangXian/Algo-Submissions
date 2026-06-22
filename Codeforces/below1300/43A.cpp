// Football

#include <iostream>
#include <string>
using namespace std;

int main() {
    string team1{};
    string team2{};
    int score1{};
    int score2{};

    int n;
    string x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (team1 == "") {
            team1 = x;
        }
        if (team1 != x && team2 == "") {
            team2 = x;
        }

        if (team1 == x) {
            score1++;
        } else if (team2 == x) {
            score2++;
        }
    }

    if (score1 > score2) {
        cout << team1;
    } else {
        cout << team2;
    }
}