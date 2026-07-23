//B. Prinzessin der Verurteilung

/*
string of n lowercase letters

MEX is the shortest string that doesnt appear as a 
contiguous substring in input

choose the lexicographically smallest MEX

find the MEX

t cases

n (1 <= n <= 1000)

sum of n over all test cases will not exceed 1000

maybe some super expensive algo
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        bool found = false;

        // Length 1
        for (char a = 'a'; a <= 'z' && !found; a++) {
            string t;
            t += a;

            if (s.find(t) == string::npos) {
                cout << t << '\n';
                found = true;
            }
        }

        // Length 2
        for (char a = 'a'; a <= 'z' && !found; a++) {
            for (char b = 'a'; b <= 'z' && !found; b++) {
                string t;
                t += a;
                t += b;

                if (s.find(t) == string::npos) {
                    cout << t << '\n';
                    found = true;
                }
            }
        }

        // Length 3
        for (char a = 'a'; a <= 'z' && !found; a++) {
            for (char b = 'a'; b <= 'z' && !found; b++) {
                for (char c = 'a'; c <= 'z' && !found; c++) {
                    string t;
                    t += a;
                    t += b;
                    t += c;

                    if (s.find(t) == string::npos) {
                        cout << t << '\n';
                        found = true;
                    }
                }
            }
        }
    }

    return 0;
}