//Grandma Capa Knits a Scarf

/*
string s of length n

palindrome

choose one lowercase letter and erase some occurrences of that 
letter in s

minimize number of erased symbols

find the min number of symbols she can erase to make
s a palindrome

t = number of test cases

*/
#include <iostream>
#include <string>
using namespace std;

int solveForC(string s, int l, int r, char c) {
    int res{};
    while (l <= r) {
        if (s[l] != s[r]) {
            if (s[l] == c) {
                l++;
                res++;
                continue;
            } else if (s[r] == c) {
                res++;
                r--;
                continue;
            } else {
                return -1;
            }
            res++;
        }
        l++;
        r--;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int l{};
        int r = s.size() - 1;

        int firstMis{};
        int secondMis{};
        bool solved{};

        while (l <= r) {
            if (s[l] != s[r]) {
                firstMis = solveForC(s, l,r,s[l]);
                secondMis = solveForC(s, l,r,s[r]);
                if (firstMis == -1 && secondMis == -1) {
                    cout << -1 << "\n";
                    break;
                } else if (firstMis == -1) {
                    cout << secondMis << "\n";
                    break;
                } else if (secondMis == -1) {
                    cout << firstMis << "\n";
                    break;
                } else {
                    cout << min(firstMis, secondMis) << "\n";
                    break;
                }
            }
            l++;
            r--;
        }
    
        if (l > r) {
            cout << 0 << "\n";
        }
    }
}