//Lost Numbers

/*
cout.flush()

array a consisting of 6 integers
unique

allowed to ask 4 queries

choose i and j, 1 <= i,j <= 6
get value of ai * aj in return

guess array a
*/
#include <unordered_set>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unordered_set<long long> s{};
    s.insert(4);
    s.insert(8);
    s.insert(15);
    s.insert(16);
    s.insert(23);
    s.insert(42);

    long long total = 1;
    for (long long x: s) {
        total *= x;
    }

    cout << "? " << 1 << " " << 1 << endl;
    long long first;
    cin >> first;
    first = sqrt(first);
    
    s.erase(first);

    cout << "? " << 2 << " " << 2 << endl;
    long long second;
    cin >> second;
    second = sqrt(second);

    s.erase(second);

    cout << "? " << 3 << " " << 4 << endl;
    long long threeNFour;
    cin >> threeNFour;

    cout << "? " << 4 << " " << 5 << endl;
    long long fourNFive;
    cin >> fourNFive;

    vector<long long> remaining{};
    for (long long x: s) {
        remaining.push_back(x);
    }

    long long third;
    long long fourth;
    long long fifth;
    long long sixth;

    for (int i = 0; i < remaining.size(); i++) {
        for (int j = 0; j < remaining.size(); j++) {
            for (int k = 0; k < remaining.size(); k++) {
                if (i == j || j == k || i == k) continue;
                if (remaining[i] * remaining[j] == threeNFour &&
                    remaining[j] * remaining[k] == fourNFive) {
                    fourth = remaining[j];
                    third = threeNFour / fourth;
                    fifth = fourNFive / fourth;
                }
            }
        }
    }

    s.erase(third);
    s.erase(fourth);
    s.erase(fifth);
    for (long long x: s) {
        sixth = x;
    }

    cout << "! " << first << " " << second << " " << third << " " << fourth << " " << fifth << " " << sixth << endl;
}